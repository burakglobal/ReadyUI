//
//  poiDetailTableViewCell.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/29/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit

protocol poiProtocol {
    func goTapped(poi:IDPoi)
    func showOnTheMapTapped(poi:IDPoi)
    func closeTapped()
    func addToFavoriteTapped(poi:IDPoi)
}


class SpreoPoiDetailTableViewCell: UITableViewCell {
    @IBOutlet weak var poiImage: UIImageView!
    @IBOutlet weak var mainView: UIView!
    @IBOutlet weak var detailView: UIView!
    @IBOutlet weak var poiTitle: UILabel!
    @IBOutlet weak var poiDetail: UILabel!
    @IBOutlet weak var poiDistance: UILabel!
    @IBOutlet weak var poiParking: UILabel!
    @IBOutlet weak var poiType: UILabel!
    @IBOutlet weak var showOnTheMapButton: UIButton!
    @IBOutlet weak var goButton: UIButton!
    @IBOutlet weak var closeButton: UIButton!
    @IBOutlet weak var addToFavoriteButton: UIButton!
    @IBOutlet weak var poiDescription: UILabel!
    @IBOutlet weak var poiHours: UILabel!
    var poi:IDPoi? {
        didSet {
            self.poiTitle.text = poi?.title
            
            let dict = IDKit.getInfoForFacility(withID: poi!.location.facilityId, atCmpusWithID: IDKit.getCampusIDs().first!)
            self.poiDetail.text = "\(dict["title"] ?? ""),Floor \(poi!.location.floorId)"
            self.poiDistance.text = ""
            self.poiParking.text = ""
            self.poiType.text = ""
            self.poiDescription.text = poi?.description
            self.poiHours.text = ""
            
            let serverURL = IDKit.getServerURL()
            let projectURL = IDKit.getProjectId()

            
            let imageUrl = "\(serverURL!)res/\(projectURL!)/\(poi?.location.campusId! ?? "")/\(poi?.location.facilityId! ?? "")/\(poi?.info["head"] ?? "")"
           
            if (verifyUrl(urlString: imageUrl)) {
                self.poiImage.loadImageFromUrl(imageUrl)
            } else {
                self.poiImage.image = UIImage.init(named: "poiHeadImage")
            }
 
            if searchInFavorites(poiId: (poi?.identifier)!) {
                self.addToFavoriteButton.setTitle("Remove Favorite", for: .normal)
            }
            
            self.goButton.dropShadow()
            self.showOnTheMapButton.dropShadow()
            self.addToFavoriteButton.dropShadow()
            self.closeButton.dropShadow()
        }
    }
    var delegate:poiProtocol?
    
    override func awakeFromNib() {
        super.awakeFromNib()
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
        // Configure the view for the selected state
    }
    
    @IBAction func closeButtonTapped(_ sender: Any) {
        delegate?.closeTapped()
    }
    @IBAction func showOnTheMapTapped(_ sender: Any) {
        delegate?.showOnTheMapTapped(poi: self.poi!)
    }
    @IBAction func goTapped(_ sender: Any) {
        delegate?.goTapped(poi: self.poi!)

    }
    @IBAction func addTapped(_ sender: Any) {
//        delegate?.addToFavoriteTapped(poi: self.poi!)
        if searchInFavorites(poiId: (poi?.identifier)!) {
            self.addToFavoriteButton.setTitle("Add Favorite", for: .normal)
            removeFavorites(poiId: (poi?.identifier)!)
        } else {
            self.addToFavoriteButton.setTitle("Remove Favorite", for: .normal)
            storeFavorite(poiId: (poi?.identifier)!)
        }
    }
}
