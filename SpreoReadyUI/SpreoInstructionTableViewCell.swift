//
//  InstructionTableViewCell.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/28/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit

class SpreoInstructionTableViewCell: UITableViewCell {

    @IBOutlet weak var instructionImage: UIImageView!
    @IBOutlet weak var instructionLabel: UILabel!
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }
    
}
