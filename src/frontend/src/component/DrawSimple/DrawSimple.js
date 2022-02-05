import "../../styles/DrawSimple/DrawSimple.css"
import React, { Component } from "react";
import Drawzone from "./Drawzone.js"


class DrawSimple extends Component {

  text_w = "e"

  render() {
    return (
      <div className="MainDraw">
        <span className="draw-title">Drawspace</span>
        <div className="drawzoned"><Drawzone/></div> 
        <span className="draw-text-zone">{this.text_w}</span>
      </div>
    );
  }
}

export default DrawSimple