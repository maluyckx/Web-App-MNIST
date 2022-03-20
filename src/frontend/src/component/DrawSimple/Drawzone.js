import React, { Component } from "react";
import eraser from "../../assets/img/eraser.png"
import pencil from "../../assets/img/pencil.png"
import undo from "../../assets/img/undo.png"
import restart from "../../assets/img/restart.png"
import start from "../../assets/img/start.png"
import HttpRequestSend from "../HttpRequestSend";

import CanvasDraw from "react-canvas-draw";

function dataURLtoFile(dataurl, filename) {
  var arr = dataurl.split(','), mime = arr[0].match(/:(.*?);/)[1],
      bstr = atob(arr[1]), n = bstr.length, u8arr = new Uint8Array(n);
  while(n--){
      u8arr[n] = bstr.charCodeAt(n);
  }
  return new File([u8arr], filename, {type:mime});
}


class Drawzone extends Component {
  
  state = {
    color: "#263238",
    width: 500,
    height: 400,
    brushRadius: 5,
    lazyRadius: 6,
    width_window: 621,
  };

  updateDimensions = () => {
    this.setState({ width_window: window.innerWidth});
    if (this.state.width_window <= 620){
      this.setState({
        width: 300,
        height: 500
      });
    } else {
      this.setState({
        width: 500,
        height: 400
      });
    }
  };
  componentDidMount() {
    window.addEventListener('resize', this.updateDimensions);
  }
  componentWillUnmount() {
    window.removeEventListener('resize', this.updateDimensions);
  }


  render() {

    return (
      <div className="containerDraw">
        <div className="draw-buttons">
            <img className="img-pencil" alt="pencil" src={pencil}
                  onClick={() => {this.setState({color: "#263238"})}}/> 
            <img className="img-eraser" alt="eraser" src={eraser}
                  onClick={() => {this.setState({color: "#FFFFFF"})}}/> 
            <img className="img-undo" alt="undo" src={undo}
                  onClick={() => {this.saveableCanvas.undo();}}/>
            <img className="img-restart" alt="restart" src={restart}
                  onClick={() => {this.saveableCanvas.eraseAll();}}/> 
            <img className="img-start" alt="start" src={start}
                  onClick={() => {
                    console.log(this.saveableCanvas.getDataURL('png', null, "#FFFFFF"));
                    HttpRequestSend("pipou.png", 1, dataURLtoFile(this.saveableCanvas.getDataURL('png', null, "#ff0000"),"pipou.png") ) 
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