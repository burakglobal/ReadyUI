//
//  SpreoLocationPopupViewController.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/30/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit

protocol spreoLocationProtocol {
    func goBackTapped()
    func continueTapped(poi:IDPoi)
    func cancelTappedLocationCheckPopup()
}
class SpreoLocationPopupViewController: UIViewController {
    @IBOutlet weak var locationLabel: UILabel!
    @IBOutlet weak var goBackButton: UIButton!
    @IBOutlet weak var continueButton: UIButton!
    @IBOutlet weak var cancelButton: UIButton!
    var delegate:spreoLocationProtocol?
    var poi:IDPoi?
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }

    @IBAction func continueTapped(_ sender: Any) {
        self.delegate?.continueTapped(poi: poi!)
    }
    
    @IBAction func goBackTapped(_ sender: Any) {
        self.delegate?.goBackTapped()
    }
    
    @IBAction func cancelTapped(_ sender: Any) {
        self.delegate?.cancelTappedLocationCheckPopup()
        
    }
    
}
