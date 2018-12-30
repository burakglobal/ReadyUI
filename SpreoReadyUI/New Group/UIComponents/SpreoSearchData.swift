//
//  searchData.swift
//  MetaWeather
//
//  Copyright © 2018 MetaWeather. All rights reserved.
//

import Foundation

class SpreoSearchData: NSObject, NSCoding {
    var searchKey: String
    var searchDate: String
    
    init(searchKey: String, searchDate: String) {
        self.searchKey = searchKey
        self.searchDate = searchDate
        
    }
    
    required convenience init(coder aDecoder: NSCoder) {
        let searchKey = aDecoder.decodeObject(forKey: "searchKey") as! String
        let searchDate = aDecoder.decodeObject(forKey: "searchDate") as! String
        self.init(searchKey: searchKey, searchDate: searchDate)
    }
    
    func encode(with aCoder: NSCoder) {
         aCoder.encode(searchKey, forKey: "searchKey")
        aCoder.encode(searchDate, forKey: "searchDate")
    }
}

class SpreoFavoriteData: NSObject, NSCoding {
    var searchKey: String
    var searchDate: String
    
    init(searchKey: String, searchDate: String) {
        self.searchKey = searchKey
        self.searchDate = searchDate
        
    }
    
    required convenience init(coder aDecoder: NSCoder) {
        let searchKey = aDecoder.decodeObject(forKey: "searchKey") as! String
        let searchDate = aDecoder.decodeObject(forKey: "searchDate") as! String
        self.init(searchKey: searchKey, searchDate: searchDate)
    }
    
    func encode(with aCoder: NSCoder) {
        aCoder.encode(searchKey, forKey: "searchKey")
        aCoder.encode(searchDate, forKey: "searchDate")
    }
}

func searchInFavorites(poiId:String) -> Bool {
    let defaults = UserDefaults.standard
    if defaults.object(forKey: "favorites") != nil {
        let decoded  = defaults.object(forKey: "favorites") as! Data
        let decodedSearches = NSKeyedUnarchiver.unarchiveObject(with: decoded) as! [SpreoFavoriteData]
        for fav in decodedSearches
        {
            if fav.searchKey==poiId{
                return true
            }
        }
    }
    return false
}

func storeFavorite(poiId:String) {
    let defaults = UserDefaults.standard
    var favorites = [SpreoFavoriteData]()
    
    if defaults.object(forKey: "favorites") != nil {
        let decoded  = defaults.object(forKey: "favorites") as! Data
        let decodedSearches = NSKeyedUnarchiver.unarchiveObject(with: decoded) as! [SpreoFavoriteData]
        favorites = decodedSearches
    }

    favorites.append(SpreoFavoriteData(searchKey: poiId, searchDate: "\(Date())"))
    let encodedData: Data = NSKeyedArchiver.archivedData(withRootObject: favorites)
    defaults.set(encodedData, forKey: "favorites")
    defaults.synchronize()
}


func removeFavorites(poiId:String) {
    let defaults = UserDefaults.standard
    var favorites = [SpreoFavoriteData]()
    
    if defaults.object(forKey: "favorites") != nil {
        let decoded  = defaults.object(forKey: "favorites") as! Data
        let decodedSearches = NSKeyedUnarchiver.unarchiveObject(with: decoded) as! [SpreoFavoriteData]
        favorites = decodedSearches
    }
    var i:Int = 0
    for fav in favorites
    {
        if fav.searchKey==poiId{
            favorites.remove(at: i)
            break
        }
        i = i + 1
    }
    
    let encodedData: Data = NSKeyedArchiver.archivedData(withRootObject: favorites)
    defaults.set(encodedData, forKey: "favorites")
    defaults.synchronize()
}
