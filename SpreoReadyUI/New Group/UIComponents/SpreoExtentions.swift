//
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/27/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import Foundation
extension UIView {
    
    // OUTPUT 1
    func dropShadow(scale: Bool = true) {
        layer.masksToBounds = false
        layer.shadowColor = UIColor.black.cgColor
        layer.shadowOpacity = 0.5
        layer.shadowOffset = CGSize(width: 1, height: 3)
        layer.shadowRadius = 5
    }
    
    // OUTPUT 2
    func dropShadow(color: UIColor, opacity: Float = 0.5, offSet: CGSize, radius: CGFloat = 1, scale: Bool = true) {
        layer.masksToBounds = false
        layer.shadowColor = color.cgColor
        layer.shadowOpacity = opacity
        layer.shadowOffset = offSet
        layer.shadowRadius = radius
    }
}

extension Collection {
    func safeSuffix(_ maxLength: Self.IndexDistance) -> Array<Element> {
        guard let index = self.index(endIndex, offsetBy: -maxLength, limitedBy: startIndex) else {
            return Array(self[startIndex ..< endIndex])
        }
        return Array(self[index ..< endIndex])
    }
}

extension UINavigationItem { 
    func addMenuButton(imageType:Int = 0) {
        let button = UIButton(type: .custom)
        button.setTitle("", for: .normal)
        
        let image = UIImage.init(named: "menu-2")
        button.setImage(image, for: .normal)
        
        button.frame = CGRect(x: 0, y: 0, width: 24, height: 24)
        button.clipsToBounds = true
        button.titleLabel?.font = UIFont.systemFont(ofSize: 17.0)
        button.layer.masksToBounds = true
        
        
        button.addTarget(self, action: #selector(menuSwitch), for: UIControlEvents.touchUpInside)
        let barButton = UIBarButtonItem(customView: button)
        
        self.leftBarButtonItem = barButton
    }
    func menuSwitch() {
        exit(0)
    }
    
}

public extension UIImageView {
    
    func loadImageFromUrl(_ imageUrl: String) {
        DispatchQueue.global().async {
            if let data = NSData(contentsOf: NSURL(string: imageUrl)! as URL) {
                if let image = UIImage.init(data: data as Data) {
                    DispatchQueue.main.async {
                        self.image = image
                    }
                } else { DispatchQueue.main.async { self.image = UIImage.init(named: "poiHeadImage") }}
            } else {DispatchQueue.main.async { self.image = UIImage.init(named: "poiHeadImage") }}
        }
    }
    
}

func verifyUrl(urlString: String?) -> Bool {
    guard let urlString = urlString,
        let url = URL(string: urlString) else {
            return false
    }
    
    return UIApplication.shared.canOpenURL(url)
}

