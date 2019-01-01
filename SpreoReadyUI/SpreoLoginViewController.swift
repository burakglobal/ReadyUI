//
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/27/18.
//  Copyright © 2018 Spreo. All rights reserved.
//


import UIKit



class spreoLoginViewController: UIViewController {
    
    var activityIndicator = UIActivityIndicatorView()
    
     @IBOutlet weak var sampleTableView: UITableView!
    
    @IBOutlet weak var infoView: UITextView!
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.activityIndicatorInit()
        
        var error : IDError? = nil
        let APIKEY = "e173ce9ec1714c1cb8fa1fd6def7044615160910552661916497521" //fe7819aaa33a45dbbb1f499f59cbb16815246399008001906839929" //"e173ce9ec1714c1cb8fa1fd6def7044615160910552661916497521"
        IDKit.setAPIKey(APIKEY, error: &error)
        IDKit.setZipPackageWithoutMaps(true)
        IDKit.setCustomUserLocationIcon(UIImage.init(named: "blue_dot"))
        IDKit.setShowNavigationMarkers(true)
        IDKit.setExitCloseToOrigin(true)
        IDKit.setNoOutdoorCampus(true)
        if((error) != nil){
            print("IDKit error! \((error?.code)!).\((error?.domain)!)")
        }
        
        IDKit.checkForDataUpdatesAndInitialise(with: self)
        
        self.activityIndicator.startAnimating()
        self.activityIndicator.backgroundColor = UIColor.black
   
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
    }
    
    /**
     * Init activity indicator
     */
    func activityIndicatorInit() {
        activityIndicator = UIActivityIndicatorView(frame: CGRect(x: 0, y: 0, width: 150, height: 150))
        activityIndicator.activityIndicatorViewStyle = UIActivityIndicatorViewStyle.whiteLarge
        activityIndicator.center = self.view.center
        activityIndicator.backgroundColor = UIColor.white
        self.view.addSubview(activityIndicator)
    }
    
    
    
    func onDataUpdateDone(){
        
        self.activityIndicator.stopAnimating()
        self.activityIndicator.hidesWhenStopped = true
        let vc = UIStoryboard.init(name: "SpreoReadyUI", bundle: Bundle.main).instantiateViewController(withIdentifier: "SpreoMapViewController") as? spreoMapViewController
        self.navigationController?.pushViewController(vc!, animated: true)
        IDKit.startUserLocationTrack()

    }
    
}




//MARK: - IDDataUpdateDelegate methods
extension spreoLoginViewController : IDDataUpdateDelegate{
    
    
    /**
     *  To get the data download status
     * - parameter aStatus: IDDataUpdateStatus enum type
     */
    func dataUpdateStatus(_ aStatus: IDDataUpdateStatus ) {
        switch (aStatus) {
        case .checkForUpdates:
            // do something, display the user the current status
            break;
        case .copyFiles:
            // do something, display the user the current status
            break;
        case .dataDownload:
            // do something, display the user the current status
            break;
        case .initialising:
            // do something, display the user the current status
            break;
        case .done:
            // do something, display the user the current status
            // when done, can start user location tracking
            self.onDataUpdateDone()
            break;
        }
    }
    
    /**
     *  To get the data download failed error description
     * - parameter anError : error description IDError
     */
    func dataUpdateFailedWithError(_ anError: IDError!) {
        
    }
    
}

