//
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/27/18.
//  Copyright © 2018 Spreo. All rights reserved.
//


import UIKit
import CoreLocation

class spreoMapViewController: UIViewController   {
    
    @IBOutlet weak var hamburgerMenuTableView: UITableView!
    @IBOutlet weak var hamburgermMenu: UIView!
    @IBOutlet weak var navButton: UIButton!
    @IBOutlet weak var myLocationButton: UIButton!
    @IBOutlet weak var searchMenu: UIView!
    @IBOutlet weak var sHamburgerIcon: UIButton!
    @IBOutlet weak var searchText: UITextField!
    @IBOutlet weak var hamburgerMenuHeight: NSLayoutConstraint!
    
    var searches = [SpreoSearchData]() // Search History
    var searchResults = [IDPoi]() // Search Results from Textbox
    var categoriesSearchResults = [IDPoi]() // Search Results from Textbox
    var selectedCategory:IDCategory?
    var mapVC : IDDualMapViewController? //IDDualMapViewController
    var instructionVC : IDInstructionsViewController? //IDInstructionsViewController
    var distanceLabel : UILabel?
    var totalDistanceLabel : UILabel?
    var presentPoiList = true //first present
    var tableviewStatus:Int = 0
    var levelPickerView:TYLevelPicker!
    var instructionPopup:SpreoInstructionPopupViewController?
    var poiDetailPopup:SpreoPoiDetailsTableViewController?
    let blankUI = UIView()
    var fromToPopup:SpreoFromToViewController?
    var locationPopup:SpreoLocationPopupViewController?
    var parkingPopup:SpreoParkingViewController?
    var locationServices:SpreoLocationServicesViewController?
    var timer: Timer?
    var timerCount:Int = 0
    var hud:MBProgressHUD?
    var campusFar = 0 //Int.max
    var favorites = [IDPoi]()
    let pois =  IDKit.sortPOIsAlphabetically(withPathID: "\(IDKit.getCampusIDs().first ?? "")")
    let categories =  IDKit.getPOIsCategoriesList(withPathID: "\(IDKit.getCampusIDs().first ?? "")")
    var rfScanner:RFScanner = RFScanner.shared()
 
    // MARK: - Life Cycle
    override func viewDidLoad() {
        super.viewDidLoad()
        
        IDKit.registerToLocationListener(withDelegate: self)
        IDKit.setNavigationSimplifiedInstructionStatus(false);
        self.rfScanner.register(with: self)

        self.initDualMapController()
        self.initInstructionController()
        self.searchText.delegate = self
        
        //set navigationDelegate
        IDKit.setNavigationDelegate(self)
        
        self.mapVC?.setMapAutoFollowUserMode(true)
        self.mapVC?.setUserAutoFollowTimeInterval(15);
        IDKit.setClusterLabel(true); // turn on for label algorithm
        self.navigationItem.title = "Map and Directions"
         searchMenu.dropShadow()
        hamburgermMenu.dropShadow()
        getHistory()
        registerNotifications()
        resetPois()
    }

    func resetPois() {
        self.mapVC?.changePOIIcons(17)
    }

    func registerNotifications() {
        let nc = NotificationCenter.default
        nc.addObserver(self, selector: #selector(closeMap), name: Notification.Name("closeMap"), object: nil)
    }
    
    func closeMap(notification : NSNotification) {
 
    }
    override func viewDidDisappear(_ animated: Bool) {
        self.mapVC = nil
        IDKit.stopUserLocationTrack()
        IDKit.unregisterLocationListenerDelegate(self)
    }
    
    override func awakeFromNib() {       
        self.navigationItem.addMenuButton()
    }
    
    override func viewDidLayoutSubviews() {
        levelPickerView?.updateView()
    }
    
    func setLevelPicker() {
        levelPickerView = TYLevelPicker.createLevelPickerView()
        levelPickerView.delegate = self
        levelPickerView.setUpViewForMapVC(self.mapVC)
        levelPickerView.add(to: self.view)
    }

    
    func getHistory() {
        // Get Stored Searches
        let defaults = UserDefaults.standard
        searches.removeAll()
        if defaults.object(forKey: "searches") != nil {
            let decoded  = try? defaults.object(forKey: "searches") as! Data
            if let decoded = decoded {
                let decodedSearches = NSKeyedUnarchiver.unarchiveObject(with: decoded) as! [SpreoSearchData]
                searches = decodedSearches
            }
        }
        if (self.searches.count > 3) { self.searches = searches.safeSuffix(3)   }
        print(searches.debugDescription)
        self.hamburgerMenuHeight.constant = CGFloat(searches.count * 50) + 150
    }
    
    func storeSearch(searchKey:String) {
        let defaults = UserDefaults.standard
        if defaults.object(forKey: "searches") != nil {
            let decoded  = defaults.object(forKey: "searches") as! Data
            let decodedSearches = NSKeyedUnarchiver.unarchiveObject(with: decoded) as! [SpreoSearchData]
            for fav in decodedSearches
            {
                if fav.searchKey==searchKey{
                    return
                }
            }
        }
        searches.append(SpreoSearchData(searchKey: searchKey, searchDate: "\(Date())"))
        let encodedData: Data = NSKeyedArchiver.archivedData(withRootObject: searches)
        defaults.set(encodedData, forKey: "searches")
        defaults.synchronize()
    }
    
    override func touchesBegan(_ touches: Set<UITouch>,
                               with event: UIEvent?) {
        self.view.endEditing(true)
    }
    
    
    func mapColorForRoute() -> UIColor! {
        return UIColor.blue;
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(true)
        
        self.mapVC?.showAllPois()
        
    }
    
    
    override func viewDidAppear(_ animated: Bool) {
        self.mapVC?.mapReload()
        
        DispatchQueue.main.asyncAfter(deadline: .now() + 1) { // in half a second...
            self.checkLocation(with: false, poi:nil)
        }
        
        self.setLevelPicker()
        self.mapVC?.putUserInCampus = false;
        self.mapVC?.setMapZoomSWFT(17)
        self.mapVC?.setMinZoom(16, maxZoom: 22)
        self.mapVC?.addTiles()
    }
    
    func mapDidLongPress(at coordinate: CLLocationCoordinate2D, facilityId: String!, floorId: String!) {
        self.mapVC?.centerCampusMap(withCampusId: IDKit.getCampusIDs().first)
    }
    
    // MARK: - PrivateMethods
    func initDualMapController(){
        self.mapVC = IDKit.getDualMapViewController()
        
        self.mapVC?.provideGoogleMapsAPIKey("AIzaSyAIN6Dy7F3Oq7Cr9bhwmy-3gkghpip1bZE")
        self.mapVC?.settings.indoorPicker = false
        self.mapVC?.settings.myLocationButton = false
        self.mapVC?.padding = UIEdgeInsetsMake(self.topLayoutGuide.length, 0, 44, 0);
        self.mapVC?.setMapRotationMode(.KIDMapRotationNavigation)
        self.mapVC?.delegate = self;
        self.addChildViewController(self.mapVC!)
        self.view.addSubview((self.mapVC?.view)!)
        self.view.sendSubview(toBack: (self.mapVC?.view)!)
    }
    
 
    fileprivate func checkLocationServices(_ poi: IDPoi?) {
        myLocationButton.isEnabled = true
        self.mapVC?.centerCampusMap(withCampusId: IDKit.getCampusIDs().first)
        IDKit.stopUserLocationTrack()
        IDKit.setDisplayUserLocationIcon(false)
        
        self.locationServices = SpreoLocationServicesViewController(nibName: "SpreoLocationServicesViewController", bundle: nil)
        self.locationServices?.view.dropShadow()
        self.locationServices?.delegate = self
        if (poi != nil) {
            self.locationServices?.poi = poi
            self.locationServices?.continueButton.isHidden = false
        }
        self.locationServices?.view.clipsToBounds = true
        let leftX = self.view.frame.width-40
        self.locationServices?.view.frame = CGRect(x: 40, y: 0, width: leftX, height:174)
        self.locationServices?.view.dropShadow()
        self.locationServices!.view.center = self.view.center
        self.locationServices!.view.alpha = 1
        self.view.addSubview((self.locationServices?.view)!)
    }
    
    fileprivate func resultLocation(_ popup: Bool, _ poi: IDPoi?) {
        if (CLLocationManager.authorizationStatus() != .authorizedAlways && CLLocationManager.authorizationStatus() != .authorizedWhenInUse) {
            checkLocationServices(poi)
        }  else {
                self.mapVC?.putUserInCampus = false
                hud = MBProgressHUD.showAdded(to: view, animated: true)
                hud?.mode = MBProgressHUDMode.indeterminate
                hud?.label.text = "Updating your location."
                hud?.detailsLabel.text = "Tap to cancel"
                hud?.isUserInteractionEnabled = true
                let tap = UITapGestureRecognizer(target: self, action: #selector(cancelButton))
                self.hud!.addGestureRecognizer(tap)
        }
        
      
        
        
                timer = Timer.scheduledTimer(timeInterval: 1, target: self, selector:#selector(fireTimer), userInfo: [ "poi" : poi as Any, "popup" : popup], repeats: true)
 }

    func cancelButton() {
        self.hud!.hide(animated: true)
        timerCount = 15
//        self.resultLocationFinalStep2(poi: nil, popup: false)
//        timer?.invalidate()
//        self.mapVC?.addTiles()
//        IDKit.setDisplayUserLocationIcon(false)
//        self.mapVC?.updateUserLocationWithSmoothlyAnimation()

    }

    func fireTimer() {
        var poi:IDPoi?
        var popup:Bool?
        
        if let userInfo = timer!.userInfo as? [String:Any] {
            if !(userInfo["poi"] is NSNull) {
                poi = userInfo["poi"] as? IDPoi
            }
            if !(userInfo["popup"] is NSNull) {
                popup = userInfo["popup"] as? Bool
            }
        }
        
        print("Timer fired!")
        timerCount += 1
    
        if IDKit.getUserLocation().inCoordinate.x != 0 && IDKit.isUser(inCampus: campusFar) {
            timerCount = 0
            timer!.invalidate()
            if ((poi) == nil) {
                let banner = Banner(title: "Location", subtitle: "Indoor Location found!", image: UIImage(named: "from_to_start_point"), backgroundColor: UIColor.black)
                banner.dismissesOnTap = true
                banner.show(duration: 3.0)
            } else {
                
            }
            IDKit.setDisplayUserLocationIcon(true)
            self.mapVC?.updateUserLocationWithSmoothlyAnimation()
            self.resultLocationFinalStep2(poi:poi, popup:popup!)
        }
        
        if (timerCount==2) {
            self.mapVC?.centerCampusMap(withCampusId: IDKit.getCampusIDs().first)
        }
        
        if timerCount > 15 {
            timerCount = 0
            timer!.invalidate()
            self.resultLocationFinal(poi:poi, popup:popup!)
        }
    }


    func resultLocationFinalStep2(poi:IDPoi?, popup:Bool) {
        hud?.hide(animated: false)
        IDKit.setDisplayUserLocationIcon(false)
        self.searchMenu.isHidden = false
        if (!IDKit.isUser(inCampus: campusFar)) {
            IDKit.setDisplayUserLocationIcon(false)
            self.mapVC?.centerCampusMap(withCampusId: IDKit.getCampusIDs().first)
            self.mapVC?.updateUserLocationWithSmoothlyAnimation()
        } else {
            IDKit.setDisplayUserLocationIcon(true)
            self.mapVC?.mapReload()
            self.mapVC?.showFloor(withID: IDKit.getUserLocation().floorId, atFacilityWithId: IDKit.getUserLocation().facilityId)
            
            if (poi != nil) {
                self.startNavigationToLocation(aLocation: poi?.location, from:nil)
            }

        }
        
       
        self.myLocationButton.isEnabled = true
        IDKit.stopUserLocationTrack()
    }

    func resultLocationFinal(poi:IDPoi?,popup:Bool) {
        if (popup) {
            self.locationPopup = SpreoLocationPopupViewController(nibName: "SpreoLocationPopupViewController", bundle: nil)
            self.locationPopup?.view.dropShadow()
            self.locationPopup?.poi = poi
            self.locationPopup?.delegate = self
            self.locationPopup?.view.clipsToBounds = true
            let leftX = self.view.frame.width-40
            self.locationPopup?.view.frame = CGRect(x: 40, y: 0, width: leftX, height:174)
            self.locationPopup?.view.dropShadow()
            self.locationPopup!.view.center = self.view.center
            self.locationPopup!.view.alpha = 1
            self.view.addSubview((self.locationPopup?.view)!)
            
        } else {
            
            let banner = Banner(title: "Location", subtitle: "No indoor location found - app will use your GPS location.\n If you are indoors, move to a new location and try again.", image: UIImage(named: "from_to_destination"), backgroundColor: UIColor.black)
            banner.dismissesOnTap = true
            banner.show(duration: 3.0)
        }
        resultLocationFinalStep2(poi: poi,popup:popup)
    }

    func checkLocation(with popup:Bool, poi:IDPoi?) {
        IDKit.setUserLocation(nil)
        IDKit.startUserLocationTrack()
        myLocationButton.isEnabled = false
        resultLocation(popup, poi)
    }

    
    func initInstructionController(){
        // get instruction controller
        self.instructionVC = IDKit.getInstructionsController()
        //self.instructionVC?.view.frame = CGRect(x: 0, y: self.topLayoutGuide.length, width: self.view.frame.width, height: 40)
        // set the instruction controller delegate
        self.instructionVC?.delegate = self
        self.instructionVC?.view.alpha = 1
        // add the instructions controller as a childe to the base view controller
        self.addChildViewController(self.instructionVC!)
        
        // add the instructions view to the view hierarchy
        self.view.addSubview((self.instructionVC?.view)!)
    }
    
   
    // MARK: - Navigation & Simulation managment
    func stopNavigation(){
        IDKit.stopNavigation()
        levelPickerView.stopNavigation()
        self.searchMenu.isHidden = false
        self.instructionVC?.dismissInstruction()
    }

    func presentPoiOnTheMap(aPoi poi: IDPoi!){
        self.mapVC?.presentPoiOnMap(with: poi)
    }
    
    func populateFavorites() {
        tableviewStatus = 4
        self.favorites.removeAll()
        for poi in pois {
            if searchInFavorites(poiId: poi.identifier) {
                favorites.append(poi)
            }
        }
        if (favorites.count > 0) {
            hamburgerMenuTableView.reloadData()
        } else {
            let banner = Banner(title: "Favorites", subtitle: "There is no Poi selected as favorite ", image: UIImage(named: "list_item_favorite"), backgroundColor: UIColor.red)
            banner.dismissesOnTap = true
            banner.show(duration: 1.0)
            self.closeSearch()
        }
        
    }
    
    func showParking() {
        self.closeSearch()
        if (parkingPopup==nil) {
            parkingPopup = SpreoParkingViewController(nibName: "SpreoParkingViewController", bundle: nil)
            parkingPopup?.view.clipsToBounds = true
            parkingPopup?.delegate = self
            parkingPopup?.view.dropShadow()
            parkingPopup!.view.frame = CGRect(x: 0.0, y: self.view.frame.height-250, width: self.view.frame.width, height:
            parkingPopup!.view.frame.height)
            parkingPopup!.view.alpha = 1
            parkingPopup!.view.transform = CGAffineTransform(scaleX: 0.8, y: 1.2)
            self.view.addSubview((parkingPopup?.view)!)
            UIView.animate(withDuration: 0.5, delay: 0, usingSpringWithDamping: 0.5, initialSpringVelocity: 0, options: [],  animations: {
                self.parkingPopup!.view.transform = .identity
            })
        }
        
    }
    
    func populatePoisFromCategories(category:String) {
        tableviewStatus = 3
        self.sHamburgerIcon.setImage(UIImage.init(named: "smallBack"), for: .normal)
        self.categoriesSearchResults = IDKit.getPOIs(withCategories: [category], atPathID: "\(IDKit.getCampusIDs().first ?? "")")
        
        if (self.categoriesSearchResults.count < 6) {
            self.hamburgerMenuHeight.constant = CGFloat(self.categoriesSearchResults.count * 50)
        } else {
            self.hamburgerMenuHeight.constant = 300
        }
        
        hamburgerMenuTableView.reloadData()
    }
    
    func populateCategories() {
        
        if (categories.count==0) {
            let banner = Banner(title: "Categories", subtitle: "No Category defined!", image: UIImage(named: "Non"), backgroundColor: UIColor.red)
            banner.dismissesOnTap = true
            banner.show(duration: 1.0)
            return
        }
        
        
        tableviewStatus = 2
        self.sHamburgerIcon.setImage(UIImage.init(named: "smallBack"), for: .normal)
        if (self.categories.count < 6) {
            self.hamburgerMenuHeight.constant = CGFloat(self.categories.count * 50)
        } else {
            self.hamburgerMenuHeight.constant = 300
        }
    
    hamburgerMenuTableView.reloadData()
    }
    
    
    func openPoi(index:Int) {
        self.view.endEditing(true)
        var poi:IDPoi?
        if (tableviewStatus==1) {
            poi = self.searchResults[index]
        } else if tableviewStatus==3 {
            poi = self.categoriesSearchResults[index]
        } else if tableviewStatus==4 {
            poi = self.favorites[index]
        } else {
            if (index < self.searches.count ) {
                for p in pois {
                    if p.identifier==self.searches[index].searchKey {
                        poi = p
                        break
                    }
                }
                
            }
        }
        openPoiPopup(poi: poi)
    }
    
    func openPoiPopup(poi:IDPoi?)
    {
        closeSearch()
        if poi != nil {
            if ((poiDetailPopup) != nil) {
                blankUI.removeFromSuperview()
                self.poiDetailPopup!.view.removeFromSuperview()
            }
            
            
            blankUI.backgroundColor = UIColor.black
            blankUI.alpha = 0.5
            blankUI.frame = self.view.frame
            self.view.addSubview(blankUI)
            
            poiDetailPopup = SpreoPoiDetailsTableViewController(nibName: "SpreoPoiDetailsTableViewController", bundle: nil)
            poiDetailPopup?.poi = poi
            poiDetailPopup?.delegate = self
            poiDetailPopup?.view.clipsToBounds = true
            
            let leftX = self.view.frame.width-40
            let rightX = self.view.frame.height 

            poiDetailPopup?.view.frame = CGRect(x: 40, y: self.topLayoutGuide.length + 200, width: leftX, height:rightX-200)
            poiDetailPopup?.view.dropShadow()
            
            poiDetailPopup!.view.center = view.center
            poiDetailPopup!.view.alpha = 1
            poiDetailPopup!.view.transform = CGAffineTransform(scaleX: 0.8, y: 1.2)
            
            self.view.addSubview((poiDetailPopup?.view)!)
            UIView.animate(withDuration: 0.5, delay: 0, usingSpringWithDamping: 0.5, initialSpringVelocity: 0, options: [],  animations: {
                self.poiDetailPopup!.view.transform = .identity
            })
         }
    }
    
    func startNavigationWithIndex(index:Int) {
        var poi:IDPoi?
        if (tableviewStatus==1) {
            storeSearch(searchKey: self.searchResults[index].identifier)
            poi = self.searchResults[index]
        } else if tableviewStatus==3 {
            storeSearch(searchKey: self.categoriesSearchResults[index].identifier)
            poi = self.categoriesSearchResults[index]
        } else {
            if (index < self.searches.count ) {
                for p in pois {
                    if p.identifier==self.searches[index].searchKey {
                        poi = p
                        break
                    }
                }

            }
        }
        closeSearch()
        if poi != nil {
            self.startNavigationToLocation(aLocation: poi!.location, from: nil)
        }
    }
    
    func startNavigationToLocation(aLocation location: IDLocation?, from:IDLocation?) {
        self.view.endEditing(true)
        self.searchMenu.isHidden = true
        self.hamburgermMenu.isHidden = true
        if (from != nil) {
            if ((from?.isIndoor)!) {
                let fromUL:IDUserLocation = IDUserLocation(campusId: from?.campusId, facilityId: from?.facilityId, outCoordinate: (from?.outCoordinate)!, inCoordinate: (from?.inCoordinate)!, andFloorId: (from?.floorId)!)
                IDKit.setUserLocation(fromUL)
                self.mapVC?.updateUserLocationWithSmoothlyAnimation()
                levelPickerView.updateViewForNavigation(toFloor: location!.floorId, fromFloor: (fromUL.floorId))
                IDKit.setDisplayUserLocationIcon(false)
            } else {
                levelPickerView.updateViewForNavigation(toFloor: location?.floorId ?? 0, fromFloor: IDKit.getUserLocation().floorId)
                
            }
        } else {
            levelPickerView.updateViewForNavigation(toFloor: location?.floorId ?? 0, fromFloor: IDKit.getUserLocation().floorId)
            
        }

        
        let res = IDKit.startNavigate(to: location!,
                            with: .navigationOptionStaff,
                            andDelegate: self)
        
        if (!res) {
            let banner = Banner(title: "Navigation", subtitle: "Navigation Error! ", image: UIImage(named: "Non"), backgroundColor: UIColor.red)
            banner.dismissesOnTap = true
            banner.show(duration: 1.0)
            IDKit.stopNavigation()
        }
    }
    
    
    func sortPOIsAlphabetically(withPathId pathId: String!) -> [IDPoi]{
        let pois =  IDKit.sortPOIsAlphabetically(withPathID: pathId)
        return pois
    }
    

    
    /**
     * The map will center the user position
     */
    func showMyLocation(){
        self.mapVC?.showMyPosition()
    }
    
    /**
     * The method set the location as parking location.
     * - parameter location: the location to set.
     */
    func saveMyParking(aLocation location : IDLocation){
        location.campusId = IDKit.getCampusIDs().first;
        IDKit.setParking(location)
    }
    
    
    /**
     * The method removes the parking location.
     */
    func removeMySavedParkingLocation(){
        IDKit.removeParkingLocation()
    }
    
    /**
     * The map will hide all pois on map
     */
    func hideAllPois(){
        self.mapVC?.hideAllPois()
    }
    
    
    
    /**
     * Set the map show visible poi categories array.
     * - parameter visibleCategories: the pois categories Array.
     * - note: in case the aCategories parameter is nil, the Map will show all Pois.
     */
    func setVisiblePOIsWithCategories(aVisibleCategories visibleCategories : [String]!){
        self.mapVC?.setVisiblePOIsWithCategories(visibleCategories)
    }
    
    /**
     * The method search  poi by id.
     * - parameter pathId: string identifier for the required POI
     * - parameter poiId: string poi identifier
     * - Returns:  IDPoi or nil
     */
    func searchPoiById(aPathId pathId : String, aPoiId poiId: String) -> IDPoi! {
        let pois = self.sortPOIsAlphabetically(withPathId: pathId)
        for poi in pois {
            if poi.identifier == poiId {
                return poi
            }
        }
        return nil
    }
    
    /**
     * The method sets  the  custom floor picker.
     */
  
    /**
     * Set the map show visible pois with ids array.
     * - parameter poisIds: pois ids [String]
     * - note: in case the aPoisIds parameter is nil, the Map will show all Pois.
     */
    func setVisiblePoisWithIds(aPoisId poisIds : [String]){
        self.mapVC?.setVisiblePOIsWithIds(poisIds)
    }
    
    /**
     * Show route overview.
     * - parameter poi: target POI, ending point of the route.
     */
    func showRouteOverview(forPoi poi: IDPoi) {
        // Stop navigation if it is currently running.
        IDKit.stopNavigation()
        // Build a route and start new navigation process. This will display the route on a map.
        IDKit.startNavigate(to: poi.location, with: .navigationOptionStaff, andDelegate: self)
        // Display destination point on a map.
        self.mapVC?.presentPoiOnMap(with: poi)
    }
    
    /**
     * Presents the campus if the user is outside of it.
     */
    
    // Navigation Buttons
    @IBAction func myLocationTapped(_ sender: Any) {
        self.stopNavigation()
        checkLocation(with: false, poi:nil)
    }
    
    func openFromTo(poi:IDPoi?) {
        
        if (fromToPopup != nil) {
            fromToPopup!.view.removeFromSuperview()
            fromToPopup = nil
        }
        
        self.navButton.tag = 100
        self.searchMenu.isHidden = true
        self.navButton.setImage(UIImage.init(named: "navigation_on"), for: .normal)
        fromToPopup = SpreoFromToViewController(nibName: "SpreoFromToViewController", bundle: nil)
        fromToPopup?.view.clipsToBounds = true
        fromToPopup?.delegate = self
        fromToPopup?.levelpickerView = self.levelPickerView
        fromToPopup?.view.dropShadow()
        fromToPopup!.view.frame = CGRect(x: 0.0, y: self.topLayoutGuide.length, width: self.view.frame.width, height: fromToPopup!.view.frame.height)
        fromToPopup!.view.alpha = 1
        fromToPopup!.view.transform = CGAffineTransform(scaleX: 0.8, y: 1.2)
        
        if ((poi) != nil) {
            fromToPopup?.toPoi = poi
            fromToPopup?.destinationViewTextbox.text  = poi?.title
        }
        
        self.view.addSubview((fromToPopup?.view)!)
        UIView.animate(withDuration: 0.5, delay: 0, usingSpringWithDamping: 0.5, initialSpringVelocity: 0, options: [],  animations: {
            self.fromToPopup!.view.transform = .identity
        })
    }
    
    @IBAction func navigationButtonTapped(_ sender: Any) {
        if (self.navButton.tag==0) {
            if (CLLocationManager.authorizationStatus() != .authorizedAlways && CLLocationManager.authorizationStatus() != .authorizedWhenInUse) {
                checkLocationServices(nil)
                locationServices?.continueButton.isHidden = false
            } else {
                openFromTo(poi: nil)
            }
        } else {
            closeNavBar()
        }

            
    }
    @IBAction func sHamburgerTapped(_ sender: Any) {
            if tableviewStatus==1 {
               closeSearch()
            }
        
        if tableviewStatus==2 || tableviewStatus==4 {
            tableviewStatus = 0
            hamburgerMenuTableView.reloadData()
            self.sHamburgerIcon.setImage(UIImage.init(named: "shamburgerIcon"), for: .normal)
            return
        } else if tableviewStatus==3 {
            tableviewStatus = 2
            populateCategories()
            return
        }
        getHistory()
        hamburgerMenuTableView.reloadData()
        self.hamburgermMenu.isHidden = self.hamburgermMenu.isHidden ? false : true
    }
    
    @IBAction func searchTextFieldChanged(_ sender: Any) {
        self.searchResults.removeAll()
        guard let stext = searchText.text else {
            return
        }
        
        if stext=="" {
            closeSearch()
            return 
        }
        
        let pois =  IDKit.sortPOIsDistantly(withPathID: "\(IDKit.getCampusIDs().first ?? "")", from: IDKit.getUserLocation())
        var newArray = [IDPoi]()
        for poi in pois {
            let kwords = poi.info["keywords"].debugDescription
            if poi.title.lowercased().contains(stext) || kwords.lowercased().contains(stext) {
                newArray.append(poi)
            }
        }
        searchResults = newArray
        self.tableviewStatus = 1
        self.hamburgerMenuTableView.reloadData()
        self.sHamburgerIcon.setImage(UIImage.init(named: "shamburgerIcon"), for: .normal)
        
        if (self.searchResults.count < 6) {
            self.hamburgerMenuHeight.constant = CGFloat(self.searchResults.count * 50)
        } else {
            self.hamburgerMenuHeight.constant = 300
        }
        
        if (searchResults.count==0) {
            hamburgermMenu.isHidden = true
        }
        self.tableViewMoveToTop()
    }
    
    func closeSearch() {
        self.tableviewStatus = 0
        searchText.text = ""
        self.sHamburgerIcon.setImage(UIImage.init(named: "shamburgerIcon"), for: .normal)
        self.hamburgermMenu.isHidden = true
        self.hamburgerMenuTableView.reloadData()
    }
    
}

extension spreoMapViewController: UITextFieldDelegate {
    func textFieldShouldReturn(_ textField: UITextField) -> Bool {
        
        textField.resignFirstResponder()
        //or
        //self.view.endEditing(true)
        return true
    }
   
    
}

// MARK: - IDLocationListener methods
extension spreoMapViewController : IDLocationListener {
    
    /**
     * This method is to be called when the location detection be changed
     * (i.e. Bloutooth mode, CoreLocation Authorization mode)
     * - parameter aStatus: IDLocationDetectionStatus enum type
     */
    func locationDetectionStatusChanged(_ aStatus: IDLocationDetectionStatus) {
        
    }
    
    /**
     * This method is to be called when the user location be updated
     * - parameter aLocation: IDUserLocation class
     */
    func updateUserLocation(with aLocation: IDUserLocation!) {
    }
    
    /**
     * This method is to be called when the user location changed for campusId
     * - parameter  aCampusId: region status changed for campus
     * - parameter  anEventType: IDRegionEventType the region event
     */
    func regionEventChanged(forCampusId aCampusId: String!, with anEventType: IDRegionEventType) {
        
    }
    
    /**
     * This method is to be called when the user location changed for facilityId at campusId
     * - parameter  aCampusId: region status changed for campus
     * - parameter  anEventType: IDRegionEventType the region event
     */
    func regionEventChangedForFacility(withID aFacilityId: String!, campusId aCampusId: String!, with anEventType: IDRegionEventType) {
        
    }
    
}

// MARK: - IDDualMapViewControllerDelegate methods
extension spreoMapViewController : IDDualMapViewControllerDelegate {
    
    /**
     * when a map my location button view did tapped
     * this method will be called in case:
     
     self.mapVC.settings.myLocationButton = YES
     * default is false
     */
    
    func mapViewForCallout(of aPoi: IDPoi!) -> UIView! {
        let calloutView = Bundle.main.loadNibNamed("CustomCalloutView", owner: self, options: nil)?[0] as? CustomCalloutView
        calloutView?.setCalloutTitle(aPoi.title, withNavIcon: aPoi.categories.contains("friends"))
        return calloutView
    }
    
    func mapDidTapCallout(of aPoi: IDPoi!) {
        if (CLLocationManager.authorizationStatus() != .authorizedAlways && CLLocationManager.authorizationStatus() != .authorizedWhenInUse) {
            checkLocationServices(aPoi)
            locationServices?.continueButton.isHidden = false
        } else {
            openFromTo(poi: aPoi)
        }
        
    }
    
    func mapDidTap(_ aPoi: IDPoi!) {
        //        IDKit.startNavigate(to: aPoi.location,
        //                            with: .navigationOptionStaff,
        //                            andDelegate: self)
        
        //        self.mapVC?.setIsIconShown(aPoi, true)
        //        self.mapVC?.setLabelAlgorithm(aPoi, true)
        //        self.mapVC?.setShowAllOnZoomLevel(aPoi, false)
        //        self.mapVC?.updatePOIIcon(aPoi, UIImage.init(named: "poiIconCustom"))
    }
    
    func mapDidTapMyLocationButton() {
        self.showMyLocation()
    }
    
    /**
     * Show custom icon image for user.
     * - Returns: image UIImage, or nil for default
     */
    func mapIconForUserAnnotaion() -> UIImage! {
        return nil
    }
    
    /**
     * Show custom icon image for Poi annotation on map
     * - parameter aPoi: IDPoi
     * - Returns: image UIImage, or nil for default
     */
    func mapIcon(for aPoi: IDPoi!) -> UIImage! {
        return nil
    }
    
    /**
     * Show custom view for parking annotation on map
     * - Returns:  image UIImage, or nil for default
     */
    func mapIconForParkingAnnotaion() -> UIImage! {
        return nil
    }
    
    /**
     * When the map did change floor map indecation at facilityId
     * - parameter aFloorId: the floor map index
     * - parameter aFacilityId: the facility of the map index
     */
    func mapDidChangeFloorId(_ aFloorId: Int, atFacilityId aFacilityId: String!) {
      levelPickerView?.update(withFloorId: aFloorId)
    }
    
}

// MARK: - IDInstructionsControllerDelegate methods
extension spreoMapViewController : IDInstructionsControllerDelegate {
    
    /**
     This method called when the user force stop navigation
     */
    func stopNavigationTapped() {
        self.stopNavigation()
        levelPickerView.stopNavigation()
        self.searchMenu.isHidden = false
    }
    
}

// MARK: - IDNavigationDelegate methods
extension spreoMapViewController : IDNavigationDelegate {
    
    /**
     * This method is to be called when navigation engine will update instruction with status
     * - parameter anInstruction: NSDictionary instruction like
     * - parameter aStatus: IDNavigationStatus enum type
     */
    func update(withInstruction anInstruction: [AnyHashable : Any]!, andStatus aStatus: IDNavigationStatus) {
        self.searchMenu.isHidden = true
        self.instructionVC?.update(withInstruction: anInstruction, andStatus: aStatus)
    }
    
    /**
     * This method is to be called when navigation engine will play instruction sound
     */
    func playInstructionSound() {
        self.instructionVC?.playInstructionSound()
    }
    
    /**
     * This method is to be called when navigation engine will update status
     * - parameter aStatus: IDNavigationStatus enum type
     */
    func navigationUpdate(with aStatus: IDNavigationStatus) {
        switch (aStatus) {
        case .navigationStart:
            // present the instruction view when navigation started
            self.instructionVC?.presentInstruction(fromOriginY: 0, toPositionY: self.topLayoutGuide.length)
            
            if (instructionPopup == nil) {
                 print(self.mapVC?.getTotalDistanceOfNavigationRoute() as Any)
                instructionPopup = SpreoInstructionPopupViewController(nibName: "SpreoInstructionPopupViewController", bundle: nil)
                var heightforInstructionPopup = self.instructionVC?.view.frame.height
                heightforInstructionPopup = heightforInstructionPopup! + CGFloat(self.instructionVC?.view.frame.origin.y ?? 0.0)
                instructionPopup?.view.frame = CGRect(x: 0, y: heightforInstructionPopup!, width: self.view.frame.width, height: 25)
                print((self.instructionVC?.view.frame.height)!)
                self.view.addSubview((instructionPopup?.view)!)
                self.view.bringSubview(toFront: (instructionPopup?.view)!)
            }
            
        case .navigationStopped:
            self.instructionVC?.dismissInstruction()
            self.searchMenu.isHidden = false
            if ((instructionPopup) != nil) {
                self.instructionPopup!.view.removeFromSuperview()
                self.instructionPopup = nil
            }
            levelPickerView.stopNavigation()
         case .navigationEnded:
            // dismiss the instruction view when navigation ended
            self.instructionVC?.dismissInstruction()
            self.searchMenu.isHidden = false
            if ((instructionPopup) != nil) {
                self.instructionPopup!.view.removeFromSuperview()
                self.instructionPopup = nil
            }
            levelPickerView.stopNavigation()
        default:
            break;
        }
    }
    
}


extension spreoMapViewController:UITableViewDataSource, UITableViewDelegate {
    
    func tableViewMoveToTop() {
        let topIndexPath:IndexPath = IndexPath(row: 0, section: 0)
        if self.searchResults.count > 0 {
            self.hamburgerMenuTableView.scrollToRow(at: topIndexPath, at: .top, animated: false)
        }
    }
    
    // MARK: - UITableViewDataSource
    func numberOfSections(in tableView: UITableView) -> Int {
        return 1
    }
    
    fileprivate func returnNumberOfRowsInSection() -> Int {
        if (self.tableviewStatus==0) {
            return self.searches.count+3
        } else if (self.tableviewStatus==1) {
            if (searchResults.count > 0) {
                self.hamburgermMenu.isHidden = false
            }
            return self.searchResults.count
            
        } else if tableviewStatus==2 {
            return self.categories.count
        } else if tableviewStatus==3 {
            return self.categoriesSearchResults.count
        } else if tableviewStatus==4 {
            return self.favorites.count
        } else {
            return 0
        }
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return returnNumberOfRowsInSection()
        
    }

    func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat {
        return 50
    }

    fileprivate func returnCells(_ indexPath: IndexPath, _ tableView: UITableView) -> UITableViewCell {
        if (self.tableviewStatus==0) {
            if (indexPath.row < self.searches.count) {
                let cell = tableView.dequeueReusableCell(withIdentifier: "HistoryTableViewCell") as! HistoryTableViewCell
                
                for poi in pois {
                    if poi.identifier==self.searches[indexPath.row].searchKey {
                        cell.poiTitle.text = poi.title
                        cell.poiTitle.tag = indexPath.row
                        cell.delegate = self
                        setGoButton(isGo: true, cell: cell)
                        cell.cellImage.image = UIImage.init(named: "search_history")
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
                        
                        break
                    }
                }
                
                return cell
                
                
            } else {
                let ind = indexPath.row - self.searches.count
                
                if ( ind==0) {
                    
                    let cell = tableView.dequeueReusableCell(withIdentifier: "MenuTableViewCell") as! MenuTableViewCell
                    cell.cellImageView.image = UIImage.init(named: "list_item_poi")
                    cell.menuTitle.text = "Categories"
                    return cell
                    
                } else if ( ind==1) {
                    
                    let cell = tableView.dequeueReusableCell(withIdentifier: "MenuTableViewCell") as! MenuTableViewCell
                    cell.cellImageView.image = UIImage.init(named: "list_item_favorite")
                    cell.menuTitle.text = "Favorites"
                    return cell
                    
                } else {
                    
                    let cell = tableView.dequeueReusableCell(withIdentifier: "MenuTableViewCell") as! MenuTableViewCell
                    cell.cellImageView.image = UIImage.init(named: "list_item_my_parking")
                    cell.menuTitle.text = "My Parking"
                    return cell
                    
                }
            }
        } else if tableviewStatus==1 {
            let cell = tableView.dequeueReusableCell(withIdentifier: "HistoryTableViewCell") as! HistoryTableViewCell
            cell.cellImage.image = UIImage.init(named: "list_item_poi")
            cell.poiTitle.text = self.searchResults[indexPath.row].title
            cell.poiTitle.tag = indexPath.row
            setGoButton(isGo: true, cell: cell)
            cell.delegate = self
            let dict = IDKit.getInfoForFacility(withID: self.searchResults[indexPath.row].location.facilityId, atCmpusWithID: IDKit.getCampusIDs().first!)
            
            
            var floor = [AnyHashable]()
            var floorTitle:String = ""
            floor = dict["floors_titles"] as! [AnyHashable]
            
            for i in 0..<floor.count {
                if (i==self.searchResults[indexPath.row].location.floorId)
                {
                    floorTitle = floor[i] as! String
                }
            }
            
            
            cell.poiDetails.text = "\(dict["title"] ?? ""),Floor \(floorTitle)"
            return cell
        } else if tableviewStatus==2 {
            let cell = tableView.dequeueReusableCell(withIdentifier: "HistoryTableViewCell") as! HistoryTableViewCell
            cell.cellImage.image = UIImage.init(named: "list_item_poi")
            cell.poiTitle.text = self.categories[indexPath.row]
            cell.poiTitle.tag = indexPath.row
            setGoButton(isGo: false, cell: cell)
            cell.delegate = self
            cell.poiDetails.text = ""
            return cell
        } else if tableviewStatus==3 {
            let cell = tableView.dequeueReusableCell(withIdentifier: "HistoryTableViewCell") as! HistoryTableViewCell
            cell.cellImage.image = UIImage.init(named: "list_item_poi")
            cell.poiTitle.text = self.categoriesSearchResults[indexPath.row].title
            cell.poiTitle.tag = indexPath.row
            cell.delegate = self
            setGoButton(isGo: true, cell: cell)
            let dict = IDKit.getInfoForFacility(withID: self.categoriesSearchResults[indexPath.row].location.facilityId, atCmpusWithID: IDKit.getCampusIDs().first!)
            
            var floor = [AnyHashable]()
            var floorTitle:String = ""
            floor = dict["floors_titles"] as! [AnyHashable]
            
            for i in 0..<floor.count {
                if (i==self.categoriesSearchResults[indexPath.row].location.floorId)
                {
                    floorTitle = floor[i] as! String
                }
            }
            
            cell.poiDetails.text = "\(dict["title"] ?? ""),Floor \(floorTitle)"
            return cell
        } else {
            let cell = tableView.dequeueReusableCell(withIdentifier: "HistoryTableViewCell") as! HistoryTableViewCell
            cell.cellImage.image = UIImage.init(named: "list_item_favorite")
            cell.poiTitle.text = self.favorites[indexPath.row].title
            cell.poiTitle.tag = indexPath.row
            cell.delegate = self
            setGoButton(isGo: true, cell: cell)
            let dict = IDKit.getInfoForFacility(withID: self.favorites[indexPath.row].location.facilityId, atCmpusWithID: IDKit.getCampusIDs().first!)
            
            var floor = [AnyHashable]()
            var floorTitle:String = ""
            floor = dict["floors_titles"] as! [AnyHashable]
            
            for i in 0..<floor.count {
                if (i==self.favorites[indexPath.row].location.floorId)
                {
                    floorTitle = floor[i] as! String
                }
            }
            
            cell.poiDetails.text = "\(dict["title"] ?? ""),Floor \(floorTitle)"
            return cell
        }
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        return returnCells(indexPath, tableView)
    }
    
    func setGoButton(isGo:Bool, cell:HistoryTableViewCell)
    {
        if (!isGo)
        {
            cell.goButton.setImage(UIImage.init(named: "smallRightArrow"), for: .normal)
            cell.goButton.backgroundColor = UIColor.clear
            cell.goButton.tintColor = UIColor.darkGray
            cell.goButton.setTitle("", for: .normal)
        } else {
            cell.goButton.setImage(nil, for: .normal)
            cell.goButton.backgroundColor = UIColor.darkGray
            cell.goButton.tintColor = UIColor.white
            cell.goButton.setTitle("GO", for: .normal)
        }

    }
    
    func tableView(_ tableView: UITableView, commit editingStyle: UITableViewCellEditingStyle, forRowAt indexPath: IndexPath) {
        if (tableviewStatus==0) {
            if editingStyle == .delete {
                let defaults = UserDefaults.standard
                defaults.removeObject(forKey: "searches")
                defaults.synchronize()
                getHistory()
                self.hamburgerMenuTableView.reloadData()
            }
        } else {
            tableView.endEditing(true)
        }
        
    }
    
    // MARK: - UITableViewDelegate
    func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath) {
        self.sHamburgerIcon.setImage(UIImage.init(named: "shamburgerIcon"), for: .normal)
        self.tableViewMoveToTop()
        print(indexPath.row)
        print(self.searches.count)
        
        if tableviewStatus==0 {
            if (indexPath.row < self.searches.count ) {
                self.openPoi(index: indexPath.row)
                return
            }
            if indexPath.row - (self.searches.count)==0 { // Categories
                self.populateCategories()
            } else if indexPath.row - (self.searches.count)==1 { // Favorites
                self.populateFavorites()
            } else if indexPath.row - (self.searches.count)==2 { // Parking
                self.showParking()
            }
            return

        } else if tableviewStatus==1 || tableviewStatus==3 || tableviewStatus==4 {
            self.openPoi(index: indexPath.row)

        } else if tableviewStatus==2 {
            self.populatePoisFromCategories(category: self.categories[indexPath.row])
        }
    
        tableView.deselectRow(at: indexPath, animated: false)
    }
}


extension spreoMapViewController:TYLevelPickerDelegate {
    func levelPicker(_ picker: TYLevelPicker!, didSelectFloor floorId: Int) {
        if floorId != self.mapVC!.currentPresentedFloorID {
            self.mapVC!.exitFollowMeMode()
            let floorIdPath = String(format: "%ld", Int(floorId))
            self.mapVC!.prepareMapForVenues(forFloorId: floorIdPath, true)
        }
    }
}

extension spreoMapViewController: historyCellDelegate {
    func navigate(index: Int) {
        self.startNavigationWithIndex(index: index)
    }
}

extension spreoMapViewController:poiProtocol {
    func goTapped(poi: IDPoi) {
        closeView()
        storeSearch(searchKey: (poi.identifier)!)
        openFromTo(poi: poi)

        
        
//        self.startNavigationToLocation(aLocation: poi.location, from: nil)
        
        
    }
    
    func showOnTheMapTapped(poi: IDPoi) {
        closeView()
        self.mapVC?.presentPoiOnMap(with: poi)
    }
    
    func closeTapped() {
       closeView()
    }
    
    func addToFavoriteTapped(poi: IDPoi) {
    }
    
    func closeView() {
        UIView.animate(withDuration: 0.1, delay: 0, usingSpringWithDamping: 0.1, initialSpringVelocity: 0, options: [], animations: {
            self.poiDetailPopup?.view.transform = CGAffineTransform(scaleX: 0.9, y: 0.9)
        }) { (success) in
            self.blankUI.removeFromSuperview()
            self.poiDetailPopup?.view.removeFromSuperview()
        }
    }
    
}

extension spreoMapViewController:SpreoFromToProtocol {
    func close() {
        closeNavBar()
    }
    
    func showOnTheMap(poi: IDPoi?) {
        self.mapVC?.presentPoiOnMap(with: poi)
    }
    
    func closeNavBar() {
        self.searchMenu.isHidden = false
        self.navButton.setImage(UIImage.init(named: "navigation_off"), for: .normal)
        self.navButton.tag = 0
        self.fromToPopup?.view.removeFromSuperview()
    }
    
    func startNavigation(from: IDPoi?, toPoi: IDPoi?) {
        closeNavBar()
        self.searchMenu.isHidden = true
         if (toPoi != nil) {
             storeSearch(searchKey: (toPoi?.identifier)!)

            if (from != nil) {
                self.startNavigationToLocation(aLocation: toPoi?.location, from:from?.location)
                self.levelPickerView.updateViewForNavigation(toFloor: toPoi?.location.floorId ?? 0, fromFloor: from?.location.floorId ?? 0)

            } else {
                checkLocation(with: true, poi:toPoi)
            }
        }
     
        
    }
    
    
}
extension spreoMapViewController:spreoLocationProtocol {
    
    func goBackTapped() {
        self.locationPopup!.view.removeFromSuperview()
        self.navigationButtonTapped(self)
    }
    
    func continueTapped(poi:IDPoi) {
        self.locationPopup!.view.removeFromSuperview()
        self.startNavigationToLocation(aLocation: poi.location, from:nil)
    }
    
    func cancelTappedLocationCheckPopup() {
        self.locationPopup!.view.removeFromSuperview()
        self.searchMenu.isHidden = false 
    }
    
}

extension spreoMapViewController:spreoParkingProtocol {
    func takeMeToMyCarTapped() {
        closeSearch()
        self.parkingPopup!.view.removeFromSuperview()
        self.parkingPopup = nil
        _ = IDKit.startNavigate(to: IDKit.getUserLocation(),
                                      with: .navigationOptionStaff,
                                      andDelegate: self)
    }
    
    func markMySpotTapped() {
        
    }
    
    func closeCancelTapped() {
        self.searchMenu.isHidden = false
        self.parkingPopup!.view.removeFromSuperview()
        self.parkingPopup = nil
    }
    
    
}

extension spreoMapViewController:spreoLocationServicesProtocol {
    func continueLocServicesTapped(poi: IDPoi?) {
        closeNavBar()
        closeLocationServices()
        IDKit.stopUserLocationTrack()
        openFromTo(poi: poi)
    }
    
    func cancelTapped() {
        closeLocationServices()
        let banner = Banner(title: "Location", subtitle: "No Location Avaliable.", image: UIImage(named: "from_to_start_point"), backgroundColor: UIColor.black)
        banner.dismissesOnTap = true
        banner.show(duration: 3.0)
    }
 
    func closeLocationServices() {
        self.locationServices?.view.removeFromSuperview()
        self.locationServices = nil
        self.searchMenu.isHidden = false
    }
    
    func openSettingsTapped() {
        closeLocationServices()
        UIApplication.shared.openURL(NSURL(string: UIApplicationOpenSettingsURLString)! as URL)
    }
    
    
}

extension spreoMapViewController:RFScannerDelegate {
    func devices(inRange devices: [Any]!) {
        print(devices.debugDescription)
    }
    
    func detectionStatusChanged(_ status: IDLocationDetectionStatus) {
        print(status)
    }
    
    
}
