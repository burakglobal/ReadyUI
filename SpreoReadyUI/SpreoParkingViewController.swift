//
//  SpreoParkingViewController.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/30/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit

protocol spreoParkingProtocol {
    func takeMeToMyCarTapped()
    func markMySpotTapped()
    func closeCancelTapped()
}
class SpreoParkingViewController: UIViewController {
    @IBOutlet weak var takeMeToMyCar: UIButton!
    @IBOutlet weak var markMySpotorDeleteParking: UIButton!
    @IBOutlet weak var cancelCloseParking: UIButton!
    var delegate:spreoParkingProtocol?
    var isParkingStored: Bool = nil != IDKit.getParkingLocation()
    
    override func viewDidLoad() {
        super.viewDidLoad()
        takeMeToMyCar.dropShadow()
        markMySpotorDeleteParking.dropShadow()
        cancelCloseParking.dropShadow()
        setButtons()
  }

    func setButtons() {
        isParkingStored = nil != IDKit.getParkingLocation()
        if isParkingStored {
            self.takeMeToMyCar.isHidden = false 
            self.takeMeToMyCar.setTitle("Take Me To My Car", for: .normal)
            self.markMySpotorDeleteParking.setTitle("Delete Parking", for: .normal)
            self.cancelCloseParking.setTitle("Close", for: .normal)
        } else {
            self.takeMeToMyCar.isHidden = true
            self.markMySpotorDeleteParking.setTitle("Mark My Spot", for: .normal)
            self.cancelCloseParking.setTitle("Cancel", for: .normal)
        }
    }
    
    @IBAction func takeMeToMyCarTapped(_ sender: Any) {
        self.delegate?.takeMeToMyCarTapped()
    }
    
    @IBAction func markMySpotTapped(_ sender: Any) {
        if (isParkingStored) {
            IDKit.removeParkingLocation()
            setButtons()
        } else {
            IDKit.setCurrentLocationAsParking()
            setButtons()
        }
        self.delegate?.markMySpotTapped()
    }
    
    @IBAction func cancelCloseTapped(_ sender: Any) {
        self.delegate?.closeCancelTapped()
    }
}
