//
//  SpreoLocationServicesViewController.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/31/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit


protocol spreoLocationServicesProtocol {
    func cancelTapped()
    func openSettingsTapped()
    func continueLocServicesTapped(poi:IDPoi?)
}

class SpreoLocationServicesViewController: UIViewController {
    @IBOutlet weak var locationServicesLabel: UILabel!
    var delegate:spreoLocationServicesProtocol?
    @IBOutlet weak var continueButton: UIButton!
    var poi:IDPoi?
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }

    @IBAction func openSettingsTapped(_ sender: Any) {
        self.delegate?.openSettingsTapped()
    }
    
    @IBAction func cancelTapped(_ sender: Any) {
        self.delegate?.cancelTapped()
    }
    @IBAction func continueTapped(_ sender: Any) {
        self.delegate?.continueLocServicesTapped(poi: self.poi)
    }
    
}
