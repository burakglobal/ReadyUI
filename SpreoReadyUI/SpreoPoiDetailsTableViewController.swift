//
//  poiDetailsTableViewController.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/29/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit

class SpreoPoiDetailsTableViewController: UITableViewController {
    var poi:IDPoi?
    var delegate:poiProtocol?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        let nib = UINib(nibName: "SpreoPoiDetailTableViewCell", bundle: nil)
        tableView.register(nib, forCellReuseIdentifier: "poiDetailCell")
        self.tableView.isScrollEnabled = true
        self.clearsSelectionOnViewWillAppear = true
        self.tableView.isUserInteractionEnabled = true
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return 1
    }

    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return self.view.frame.height
    }

    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "poiDetailCell", for: indexPath) as! SpreoPoiDetailTableViewCell
        cell.poi = self.poi
        cell.delegate = self
        return cell
    }
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        tableView.deselectRow(at: indexPath, animated: false)
    }
    
}

extension SpreoPoiDetailsTableViewController:poiProtocol {
    func goTapped(poi: IDPoi) {
        self.delegate?.goTapped(poi: poi)
    }
    
    func showOnTheMapTapped(poi: IDPoi) {
        self.delegate?.showOnTheMapTapped(poi: poi)
    }
    
    func closeTapped() {
        self.delegate?.closeTapped()
    }
    
    func addToFavoriteTapped(poi: IDPoi) {
        self.delegate?.addToFavoriteTapped(poi: poi)
    }
    
    
}
