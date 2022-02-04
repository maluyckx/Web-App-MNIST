import React, { Component } from "react";
import { render } from "react-dom";
import eraser from "../../assets/img/eraser.png"
import pencil from "../../assets/img/pencil.png"
import undo from "../../assets/img/undo.png"
import restart from "../../assets/img/restart.png"
import start from "../../assets/img/start.png"

import CanvasDraw from "react-canvas-draw";

class Drawzone extends Component {
  state = {
    color: "#263238",
    width: 500,
    height: 400,
    brushRadius: 5,
    lazyRadius: 6,
  };

  render() {
    return (
      <div className="containerDraw">
        <div className="buttons">
            <img className="img-pencil" alt="eraser" src={pencil}
                  onClick={() => {this.setState({color: "#263238"})}}/> 
            <img className="img-eraser" alt="eraser" src={eraser}
                  onClick={() => {this.setState({color: "#FFFFFF"})}}/> 
            <img className="img-undo" alt="undo" src={undo}
                  onClick={() => {this.saveableCanvas.undo();}}/>
            <img className="img-restart" alt="restart" src={restart}
                  onClick={() => {this.saveableCanvas.eraseAll();}}/> 
            <img className="img-start" alt="start" src={start}
                  onClick={() => {
                    console.log(this.saveableCanvas.getDataURL());
                  }}/>
        </div>
        <CanvasDraw className="canvaDraw"
          ref={canvasDraw => (this.saveableCanvas = canvasDraw)}
          brushColor={this.state.color}
          brushRadius={this.state.brushRadius}
          lazyRadius={this.state.lazyRadius}
          canvasWidth={this.state.width}
          canvasHeight={this.state.height}
          hideInterface="false"
        />

      </div>
    );
  }
}

export default Drawzone