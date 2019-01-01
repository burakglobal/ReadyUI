//
//  FromToViewController.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/29/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit

protocol SpreoFromToProtocol {
    func close()
    func startNavigation(from:IDPoi?, toPoi:IDPoi?)
    func showOnTheMap(poi:IDPoi?)
}

class SpreoFromToViewController: UIViewController,UITextFieldDelegate {
    @IBOutlet weak var originIcon: UIImageView!
    @IBOutlet weak var destinationIcon: UIImageView!
    @IBOutlet weak var originView: UIView!
    @IBOutlet weak var originViewIcon: UIImageView!
    @IBOutlet weak var originViewTextbox: UITextField!
    @IBOutlet weak var destinationView: UIView!
    @IBOutlet weak var destinationViewIcon: UIImageView!
    @IBOutlet weak var destinationViewTextbox: UITextField!
    @IBOutlet weak var startNavigation: UIButton!
    @IBOutlet weak var closeButton: UIButton!
    var delegate:SpreoFromToProtocol?
    var fromPoi:IDPoi?
    var toPoi:IDPoi?
    var fromSearchPopup:SpreoFromToSearchResultsTableViewController?
    var toSearchPopup:SpreoFromToSearchResultsTableViewController?
    var currentTop:CGFloat?
    var searchType = 0
    var focused = 0
    
     override func viewDidLoad() {
        super.viewDidLoad()
        startNavigation.dropShadow()
        originView.dropShadow()
        destinationView.dropShadow()
        self.originViewTextbox.delegate = self
        self.destinationViewTextbox.delegate = self
    }
    
    override func viewDidAppear(_ animated: Bool) {
        self.currentTop = self.view.frame.origin.y
    }

    @IBAction func closeTapped(_ sender: Any) {
        IDKit.stopNavigation()
        delegate?.close()
    }
    
    @IBAction func startNavigationTapped(_ sender: Any) {
        self.delegate!.startNavigation(from: fromPoi, toPoi: toPoi)
    }
    
    func closeOriginPopup() {
        self.startNavigation.isHidden = false
        self.view.frame = CGRect(x: 0, y: self.currentTop!, width: self.view.frame.width, height: 184)
        fromSearchPopup?.view.removeFromSuperview()
        fromSearchPopup = nil
        toSearchPopup?.view.removeFromSuperview()
        toSearchPopup = nil
        IDKit.stopNavigation()
    }
    
    @IBAction func fromUnTapped(_ sender: Any) {
        closeOriginPopup()
    }
    
    @IBAction func fromTapped(_ sender: Any) {
        searchType = 1
        focused = 1
        openFromSearch()
    }
    
    @IBAction func toTapped(_ sender: Any) {
        searchType = 1
        focused = 2
        openToSearch()
    }
    
    @IBAction func fromTextChanged(_ sender: Any) {
        focused = 0
        searchType = 0
        openFromSearch()
    }
    
    func openFromSearch() {
        if (searchType==0) {
            guard originViewTextbox.text != "" else {
                closeOriginPopup()
                return
            }
        }
        
        if fromSearchPopup != nil {
            fromSearchPopup!.view.removeFromSuperview()
        }
        if ((toSearchPopup) != nil) {
            self.toSearchPopup!.view.removeFromSuperview()
        }
        
        self.startNavigation.isHidden = true
        if (searchType==0){
            self.view.frame = CGRect(x: 0, y: self.currentTop!, width: self.view.frame.width, height: 310)
        } else {
            self.view.frame = CGRect(x: 0, y: self.currentTop!, width: self.view.frame.width, height: 260)
        }
        
        fromSearchPopup = SpreoFromToSearchResultsTableViewController(nibName: "SpreoFromToSearchResultsTableViewController", bundle: nil)
        fromSearchPopup?.searchType = searchType
        fromSearchPopup?.view.tag = 100
        print(self.view.frame.height)
        print(self.view.frame.origin.y)
        if (searchType==0){
            fromSearchPopup?.view.frame = CGRect(x: 0, y: self.currentTop!+50, width: self.view.frame.width, height: 200)
        } else {
            fromSearchPopup?.view.frame = CGRect(x: 0, y: self.currentTop!+50, width: self.view.frame.width, height: 150)
        }
        fromSearchPopup?.searchText = originViewTextbox.text
        fromSearchPopup?.delegate = self
        self.view.addSubview((fromSearchPopup?.view)!)
        self.view.bringSubview(toFront: (fromSearchPopup?.view)!)
    }
    
    @IBAction func toTextChanged(_ sender: Any) {
        searchType = 0
        focused = 0
        openToSearch()
    }
    func openToSearch() {
        
        if (searchType==0) {
            guard destinationViewTextbox.text != "" else {
                closeOriginPopup()
                return
            }
        }
      
        
        if toSearchPopup != nil {
            toSearchPopup!.view.removeFromSuperview()
        }
        
        
        
        if ((toSearchPopup) != nil) {
            self.toSearchPopup!.view.removeFromSuperview()
        }
        
        self.startNavigation.isHidden = true
        if (searchType==0){
            self.view.frame = CGRect(x: 0, y: self.currentTop!, width: self.view.frame.width, height: 310)
        } else {
            self.view.frame = CGRect(x: 0, y: self.currentTop!, width: self.view.frame.width, height: 260)
        }
        toSearchPopup = SpreoFromToSearchResultsTableViewController(nibName: "SpreoFromToSearchResultsTableViewController", bundle: nil)
        toSearchPopup?.searchType = searchType
        print(self.view.frame.height)
        print(self.view.frame.origin.y)
        if (searchType==0){
            toSearchPopup?.view.frame = CGRect(x: 0, y: self.currentTop!+50, width: self.view.frame.width, height: 200)
        } else {
            toSearchPopup?.view.frame = CGRect(x: 0, y: self.currentTop!+50, width: self.view.frame.width, height: 150)
        }
        toSearchPopup?.searchText = destinationViewTextbox.text
        toSearchPopup?.delegate = self
        print((self.toSearchPopup?.view.frame.height)!)
        self.view.addSubview((toSearchPopup?.view)!)
        self.view.bringSubview(toFront: (toSearchPopup?.view)!)
    }
    
}

extension SpreoFromToViewController:spreoFromToTableViewProtocol {
    func returnSelected(poi: IDPoi?) {
        self.view.endEditing(true)
        if (searchType==0) {
            if (fromSearchPopup != nil) {
                fromPoi = poi
                self.originViewTextbox.text = poi?.title
            } else {
                toPoi = poi
                self.destinationViewTextbox.text = poi?.title
            }
        } else {
            if (focused==1) {
                fromPoi = poi
                self.originViewTextbox.text = poi?.title
            } else {
                toPoi = poi
                self.destinationViewTextbox.text = poi?.title
            }
        }
        
       
        self.delegate?.showOnTheMap(poi: poi)
        closeOriginPopup()
        
        if (fromPoi != nil) {
            let fromUL:IDUserLocation = IDUserLocation(campusId: fromPoi!.location.campusId, facilityId: fromPoi!.location.facilityId, outCoordinate: (fromPoi?.location.outCoordinate)!, inCoordinate: (fromPoi?.location.inCoordinate)!, andFloorId: (fromPoi?.location.floorId)!)
            IDKit.setUserLocation(fromUL)
            IDKit.setDisplayUserLocationIcon(false)
        }
        
        if (fromPoi != nil && toPoi != nil) {
            IDKit.startNavigate(to: (toPoi?.location)!, with: IDNavigationOptions.navigationOptionRegular, andDelegate: self)
            let mapVC = IDKit.getDualMapViewController()
            mapVC.setMapZoomSWFT(19)
        }
        
    }
    
    
}


// MARK: - IDNavigationDelegate methods
extension SpreoFromToViewController : IDNavigationDelegate {


}

