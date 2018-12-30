//
//  HistoryTableViewCell.swift
//  SpreoReadyUI
//
//  Created by BURAK KEBAPCI on 12/27/18.
//  Copyright © 2018 Spreo. All rights reserved.
//

import UIKit
protocol historyCellDelegate {
    func navigate(index:Int)
}

class HistoryTableViewCell: UITableViewCell {
    @IBOutlet weak var cellImage: UIImageView!
    @IBOutlet weak var poiTitle: UILabel!
    @IBOutlet weak var poiDetails: UILabel!
    @IBOutlet weak var goButton: UIButton!
    @IBOutlet weak var seperatorView: UIView!
    var delegate:historyCellDelegate?
    
    override func awakeFromNib() {
        super.awakeFromNib()
    }
    @IBAction func goButtonTapped(_ sender: Any) {
        delegate?.navigate(index: self.poiTitle.tag)
    }
    
    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)
    }

}
