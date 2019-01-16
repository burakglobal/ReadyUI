//
//  InstructionTableViewController.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/28/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit
class SpreoInstructionTableViewController: UITableViewController {
    var instructionsList:IDCombinedRoute?
    var instructions = [Any]()
    var instructionsJson = [JSON]()
    var poi:IDPoi?
    override func viewDidLoad() {
        super.viewDidLoad()
        let nib = UINib(nibName: "SpreoInstructionTableViewCell", bundle: nil)
        tableView.register(nib, forCellReuseIdentifier: "instructionCell")
        
        if (instructionsList != nil) {
            
//            if (!IDKit.isUser(inCampus: 0)) {
//                let jsonObject: [String: Any] = [
//                    "id": 20
//                ]
//                let desJson:JSON = JSON(jsonObject)
//                instructionsJson.append(desJson)
//            }
            
            
            for ins in (instructionsList?.routes)! {
                if ins is IDCombinedRoute {
                    let d:IDCombinedRoute = ins as! IDCombinedRoute
                    print(d.getFirstRoute()?.instructions as Any)
                    for ge in (d.getFirstRoute()?.instructions)! {
                        instructions.append(ge)
                        instructionsJson.append(JSON(ge))
                    }
                }
            }
            self.tableView.isScrollEnabled = true
            self.clearsSelectionOnViewWillAppear = true
            self.tableView.isUserInteractionEnabled = true
            print(instructions)
//            instructionsJson = JSON(instructions).arrayValue
            
        }

        let jsonObject: [String: Any] = [
            "id": 7
        ]
        let desJson:JSON = JSON(jsonObject)
        if (self.instructionsJson.count > 0) {
            var instDic = self.instructionsJson[instructionsJson.count-1];
            if instDic["id"] != 7 {
                instructionsJson.append(desJson)
            }
        }

    }

    // MARK: - Table view data source

    override func numberOfSections(in tableView: UITableView) -> Int {
       
        return 1
    }

    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return instructionsJson.count
    }
    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 50
    }
   
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCell(withIdentifier: "instructionCell", for: indexPath) as! SpreoInstructionTableViewCell
        var instDic = self.instructionsJson[indexPath.row];
        print(instDic)
        print(instDic["id"].stringValue)
        if (instDic["id"].int==0) {
            cell.instructionLabel.text = "Go straight";
            cell.instructionImage.image = UIImage.init(named: "straight.png")
        } else if (instDic["id"].int==1) {
            cell.instructionLabel.text = "Turn left"
            cell.instructionImage.image = UIImage.init(named: "turn_left.png")
        } else if (instDic["id"].int==2) {
            cell.instructionLabel.text = "Stay on the left"
            cell.instructionImage.image = UIImage.init(named: "left_hall.png")
        } else if (instDic["id"].int==3) {
            cell.instructionLabel.text = "Turn right"
            cell.instructionImage.image = UIImage.init(named: "turn_right.png")
        } else if (instDic["id"].int==4) {
            cell.instructionLabel.text = "Stay on the right"
            cell.instructionImage.image = UIImage.init(named: "right_hall.png")
        } else if (instDic["id"].int==5) {
            
           
            if (instDic["parameter"].stringValue != "") {
                let startFloorTitle = IDKit.getInfoForFloorID(
                    (instDic["parameter"].intValue),
                    inFacilityWithID: instDic["facilityId"].stringValue,
                    atCmpusWithID: instDic["campusId"].stringValue);
                cell.instructionLabel.text = "Go up to floor \(startFloorTitle["title"] ?? "")"
                cell.instructionImage.image = UIImage.init(named: "elevator_up.png")
            }
            
        } else if (instDic["id"].int==6) {
            if (instDic["parameter"].stringValue != "") {
                let startFloorTitle = IDKit.getInfoForFloorID(
                    (instDic["parameter"].intValue),
                    inFacilityWithID:  instDic["facilityId"].stringValue,
                    atCmpusWithID: instDic["campusId"].stringValue);
                cell.instructionLabel.text = "Go down to floor \(startFloorTitle["title"] ?? "")"
                
                cell.instructionImage.image = UIImage.init(named: "elevator_down.png")
            }
     
        } else if (instDic["id"].int==7) {
            cell.instructionLabel.text = "You have arrived at your destination"
            cell.instructionImage.image = UIImage.init(named: "map_destination")
        } else if (instDic["id"].int==8) {
            cell.instructionLabel.text = "Turn back"
            cell.instructionImage.image = UIImage.init(named: "turn_back.png")
        } else if (instDic["id"].int==9) {
            cell.instructionLabel.text = "Recalculate"
            cell.instructionImage.image = UIImage.init(named: "map_destination.png")
        } else if (instDic["id"].int==10) {
            cell.instructionLabel.text = "Go straight"
            cell.instructionImage.image = UIImage.init(named: "continue_to_destination.png")
        } else if (instDic["id"].int==11) {
            cell.instructionLabel.text = "Follow the line"
            cell.instructionImage.image = UIImage.init(named: "continue_to_path.png")
        } else if (instDic["id"].int==12) {
            cell.instructionLabel.text = "Follow the line"
            cell.instructionImage.image = UIImage.init(named: "continue_to_path.png")
        } else if (instDic["id"].int==13) {
            cell.instructionLabel.text = "You have arrived at your destination"
            cell.instructionImage.image = UIImage.init(named: "map_destination")
        }
//        else if (instDic["id"].int==20) {
//            cell.instructionLabel.text = "Follow the Google Route to closest Parking Location (Tap to open Google)"
//            cell.instructionImage.image = UIImage.init(named: "map_destination")
//        }
 
        
         return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
//        let ins = instructionsJson[0]
//        if (ins["id"].intValue==20) {
//            if let poi=poi {
//                if  let url:URL = URL(string: "https://www.google.com/maps/place/\(IDKit.getNearbyParking(for: poi)?.location.outCoordinate.latitude ?? 0.0000),\(IDKit.getNearbyParking(for: poi)?.location.outCoordinate.longitude ?? 0.0000)") {
//                if UIApplication.shared.canOpenURL(url) {
//                    if #available(iOS 10.0, *) {
//                        UIApplication.shared.open(url, options: [:], completionHandler: nil)
//                    } else {
//                        // Fallback on earlier versions
//                    }
//                    //If you want handle the completion block than
//                    if #available(iOS 10.0, *) {
//                        UIApplication.shared.open(url, options: [:], completionHandler: { (success) in
//                            print("Open url : \(success)")
//                        })
//                    } else {
//                        // Fallback on earlier versions
//                    }
//                }
//              }
//            }
//        }
        tableView.deselectRow(at: indexPath, animated: true )

        
    }
    
}
