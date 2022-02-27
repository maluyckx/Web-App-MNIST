import React, { Component } from "react";

import "../../styles/ImageMain.css"
import BlockChoice from "../Home/BlockChoice";
import upload from "../../assets/img/upload.png"
import HttpRequestSend from "../HttpRequestSend";
import HttpRequestReceive from "../HttpRequestReceive";

class ImageMain extends Component {

  state = {
    selectedFile: null,
    text_ia: "Tartine",
  };
  
  // On file select (from the pop up)
  onFileChange = event => {
    this.setState({ selectedFile: event.target.files[0] });
    HttpRequestReceive(1);
  };
  
  onFileUpload = () => {
    this.setState({text_ia: "upload"});
    HttpRequestSend(this.state.selectedFile.name, 1, this.state.selectedFile);
  };

  infoFile = () => {
    if (this.state.selectedFile) {
      if (this.state.selectedFile.type === 'image/jpeg' 
       || this.state.selectedFile.type === 'image/png') {
        return (
          <span className="image-infos">
            {this.state.selectedFile.name}
          </span>
        )
      }
      else {
        return (
          <span className="image-infos">
            file needs to be an image 
          </span> 
        )
      }
    }
    else {
      return (
        <span className="image-infos">
          nothing.jpg
        </span>
      )
    }
  }

  render() {
    return (
      <div className="ImageMain">
        <h2>Image</h2>
        <div className="image-container">

          <div class="upload">
            <label htmlFor={"upload-button"}>
              <BlockChoice name={"Upload"} 
                          img_link={upload} 
                          description={"Click Me !"} 
                          link_to={""}/>
            </label>
            <input type="file" id="upload-button" style={{display: 'none'}} 
                  onChange={this.onFileChange} accept="image/x-png,image/jpeg" />
          </div>   

          <div className="text-analyze">
            <div className="text-file">
              {this.infoFile()}
              <button className="text-send" onClick={this.onFileUpload}>
                send
              </button>
            </div>
            <span className="text-block">
              {this.state.text_ia}
            </span>
          </div>
        </div>
      </div>
    );
  }
}

export default ImageMain