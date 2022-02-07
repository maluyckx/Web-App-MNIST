import React, { Component } from "react";
import BlockChoice from "./BlockChoice";
import "../../styles/Home/Home.css"

class Home extends Component {

  render() {
    return (
      <div className="HomeMain">
        <h2>The Tartine Network</h2>
        <div className="home-container">
          <BlockChoice name={"Game"} 
                       img_link={"https://cdn.discordapp.com/attachments/718214061283737712/937028286939287632/Daco_4300598.png"} 
                       description={"Le jeu qui utilise notre super IA"} 
                       link_to={"game"}/>
          <BlockChoice name={"Drawing"} 
                       img_link={"https://cdn.discordapp.com/attachments/718214061283737712/937027342201655356/SeekPng.com_patriots-logo-png_295350.png"} 
                       description={"Juste tu dessines et hop ca detecte ton mot, bien pour les tests"} 
                       link_to={"draw"}/>
          <BlockChoice name={"Image"}
                       img_link={"https://cdn.discordapp.com/attachments/718214061283737712/938107948184514580/photo.png"} 
                       description={"Photo/imge vers le texte"} 
                       link_to={"image"}/>
        </div>
      </div>
    );
  }
}

export default Home