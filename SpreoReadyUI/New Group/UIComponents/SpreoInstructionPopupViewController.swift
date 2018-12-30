//
//  InstructionPopupViewController.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/28/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit

class SpreoInstructionPopupViewController: UIViewController {
    var popupIsOpen:Bool = false
    @IBOutlet var popupView: UIView!
    @IBOutlet weak var detailsButton: UIButton!
    var instructionTableViewController:SpreoInstructionTableViewController?
    var heightMe:CGFloat = 0.0
    override func viewDidLoad() {
        super.viewDidLoad()
        heightMe = self.view.frame.height
    }

    @IBAction func detailsButtonTapped(_ sender: Any) {
        if popupIsOpen {
            self.instructionTableViewController!.view.removeFromSuperview()
            self.detailsButton.setTitle("Show details", for: .normal)
            self.detailsButton.setImage(UIImage.init(named: "down-arrow"), for: .normal)
            self.instructionTableViewController = nil
            popupIsOpen = false
            self.view.frame = CGRect(x: 0.0, y: self.view.frame.origin.y, width: self.view.frame.width, height: self.heightMe)
            self.detailsButton.frame = CGRect(x: 0.0, y: 0.0, width: self.view.frame.width, height: heightMe)
        } else {
            popupIsOpen = true
            self.detailsButton.setTitle("Hide details", for: .normal)
            self.detailsButton.setImage(UIImage.init(named: "up-arrow"), for: .normal)
            self.detailsButton.frame = CGRect(x: 0.0, y: 0.0, width: self.view.frame.width, height: heightMe)
            var instructionController: IDInstructionsViewController?
            instructionController = IDKit.getInstructionsController() 
            instructionTableViewController = SpreoInstructionTableViewController(nibName: "SpreoInstructionTableViewController", bundle: nil)
            if (instructionController?.instructionsList != nil) {
                instructionTableViewController?.instructionsList = (instructionController?.instructionsList)!
                instructionTableViewController?.view.frame = CGRect(x: 0, y: self.view.frame.height, width: self.view.frame.width, height: (instructionTableViewController?.view.frame.height)!)
                self.view.frame = CGRect(x: 0.0, y: self.view.frame.origin.y, width: self.view.frame.width, height: heightMe+(instructionTableViewController?.view.frame.height)!)
                self.view.addSubview((instructionTableViewController?.view)!)
                self.view.bringSubview(toFront: (instructionTableViewController?.view)!)
            }

        }
    }
    
    

}
