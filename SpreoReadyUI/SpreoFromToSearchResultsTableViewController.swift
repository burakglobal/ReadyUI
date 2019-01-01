//
//  SpreoFromToSearchResultsTableViewController.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/29/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit

protocol spreoFromToTableViewProtocol {
    func returnSelected(poi:IDPoi?)
}

class SpreoFromToSearchResultsTableViewController: UITableViewController {
    let pois =  IDKit.sortPOIsAlphabetically(withPathID: "\(IDKit.getCampusIDs().first ?? "")")
    var searchResults = [IDPoi]() // Search Results from Textbox
    var delegate:spreoFromToTableViewProtocol?
    var history = [SpreoSearchData]() // Search History
    var searchType = 0
    var searchText:String? {
        didSet {
            fireSearch(searchText: searchText!)
        }
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        let nib = UINib(nibName: "SpreoFromToTableViewCell", bundle: nil)
        tableView.register(nib, forCellReuseIdentifier: "SpreoFromToTableViewCell")
        getHistory()
    }
    
    func getHistory() {
        let defaults = UserDefaults.standard
        history.removeAll()
        if defaults.object(forKey: "searches") != nil {
            let decoded  = defaults.object(forKey: "searches") as! Data
            let decodedSearches = NSKeyedUnarchiver.unarchiveObject(with: decoded) as! [SpreoSearchData]
            history = decodedSearches
        }
        if (self.history.count > 3) { self.history = history.safeSuffix(3)   }
    }

    
    func fireSearch(searchText:String) {
        let pois =  IDKit.sortPOIsDistantly(withPathID: "\(IDKit.getCampusIDs().first ?? "")", from: IDKit.getUserLocation())
        var newArray = [IDPoi]()
        for poi in pois {
            let kwords = poi.info["keywords"].debugDescription
            if poi.title.lowercased().contains(searchText) || kwords.lowercased().contains(searchText) {
                newArray.append(poi)
            }
        }
        self.searchResults = newArray
        self.tableView.reloadData()
        
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        if searchType==0 {
          return searchResults.count
        } else {
            if (view.tag==100) {
                return history.count+1

            } else {
                return history.count

            }
        }
        
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        if searchType==0 {
            let index = indexPath.row
            let cell = tableView.dequeueReusableCell(withIdentifier: "SpreoFromToTableViewCell") as! SpreoFromToTableViewCell
            cell.poiIcon.image = UIImage.init(named: "list_item_poi")
            cell.poiTitle.text = self.searchResults[index].title
            cell.poiTitle.tag = indexPath.row
            let dict = IDKit.getInfoForFacility(withID: self.searchResults[index].location.facilityId, atCmpusWithID: IDKit.getCampusIDs().first!)
            var floor = [AnyHashable]()
            var floorTitle:String = ""
            floor = dict["floors_titles"] as! [AnyHashable]
            
            for i in 0..<floor.count {
                if (i==self.searchResults[index].location.floorId)
                {
                    floorTitle = floor[i] as! String
                }
            }
            
            cell.poiDetails.text = "\(dict["title"] ?? ""),Floor \(floorTitle)"
            return cell
        } else {
            let cell = tableView.dequeueReusableCell(withIdentifier: "SpreoFromToTableViewCell") as! SpreoFromToTableViewCell

            if (indexPath.row==0 && self.view.tag==100){
                cell.poiIcon.image = UIImage.init(named: "from_to_start_point")
                cell.poiTitle.text = "My current location"
                cell.poiTitle.tag = indexPath.row
                cell.poiDetails.text = ""
            } else {
                var index = indexPath.row
                if view.tag==100 { index = index - 1 }
                for poi in pois {
                    if poi.identifier==self.history[index].searchKey {
                        cell.poiIcon.image = UIImage.init(named: "search_history")
                        cell.poiTitle.text = poi.title
                        cell.poiTitle.tag = index
                        let dict = IDKit.getInfoForFacility(withID: poi.location.facilityId, atCmpusWithID: IDKit.getCampusIDs().first!)
                        
                        var floor = [AnyHashable]()
                        var floorTitle:String = ""
                        floor = dict["floors_titles"] as! [AnyHashable]
                        
                        for i in 0..<floor.count {
                            if (i==poi.location.floorId)
                            {
                                floorTitle = floor[i] as! String
                            }
                        }
                        
                        cell.poiDetails.text = "\(dict["title"] ?? ""),Floor \(floorTitle)"
                        
                    }
                }

            }
            
            return cell
        }
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        self.view.removeFromSuperview()
        if searchType==0 {
            self.delegate?.returnSelected(poi: self.searchResults[indexPath.row])
        }
        else {
            if (indexPath.row==0 && self.view.tag==100){
                self.delegate?.returnSelected(poi:nil)
            } else {
                var index = indexPath.row
                if (view.tag==100) {
                    index = index - 1
                }
                
                for poi in pois {
                    if poi.identifier==self.history[index].searchKey {
                        self.delegate?.returnSelected(poi:poi)
                        return
                    }
                }
            }
        }
    }

}
