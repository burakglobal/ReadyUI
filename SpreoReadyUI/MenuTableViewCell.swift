//
//  MenuTableViewCell.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/27/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit

class MenuTableViewCell: UITableViewCell {
    @IBOutlet weak var cellImageView: UIImageView!
    @IBOutlet weak var menuTitle: UILabel!
    @IBOutlet weak var goButton: UIButton!
    @IBOutlet weak var seperator: UIView!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    @IBAction func goButtonTapped(_ sender: Any) {
    }
    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
