import "../../styles/DrawSimple/DrawSimple.css"
import React, { Component } from "react";
import Drawzone from "./Drawzone.js"


class DrawSimple extends Component {
  state = {
    text_w: "",
  };

  render() {
    return (
      <div className="MainDraw">
        <span className="draw-title">Drawspace</span>
        <div className="drawzoned"><Drawzone parent={this} /></div> 
        <span className="draw-text-zone">{this.state.text_w}</span>
      </div>
    );
  }

  updateText(value) {
    this.setState({text_w: value});
  }
}

export default DrawSimple