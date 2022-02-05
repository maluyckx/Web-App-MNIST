import React, { Component } from "react";
import "../../styles/Game/MainGame.css"
import Drawgame from "./DrawGame";

class MainGame extends Component {
  render() {
    return (
      <div className="MainGame">
        <div className="GameZone">
          Le jeu doit etre dispo sur tel et pc, et j'imagine qu'il doit etre plus opti sur tel,
          donc voilà la raison de l'affichage comme ca, il faudrait l'expliquer
        </div>
        <Drawgame  />
      </div>
    );
  }
}

document.addEventListener('keydown', function(event){
  if (event.keyCode == 13 || event.keyCode == 32){
    alert("ENTER")
  }
})

export default MainGame