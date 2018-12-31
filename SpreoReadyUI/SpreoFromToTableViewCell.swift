//
//  SpreoFromToTableViewCell.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/29/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit

class SpreoFromToTableViewCell: UITableViewCell {

    @IBOutlet weak var poiTitle: UILabel!
    @IBOutlet weak var poiDetails: UILabel!
    @IBOutlet weak var poiIcon: UIImageView!
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
}
