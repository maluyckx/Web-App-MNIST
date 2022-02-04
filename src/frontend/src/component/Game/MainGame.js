import React, { Component } from "react";
import "../../styles/Game/MainGame.css"
import Drawgame from "./DrawGame";
import Celest from "../../assets/img/celeste-game.jpg"

class MainGame extends Component {
  render() {
    return (
      <div className="MainGame">
        <div className="GameZone">
          <img src={Celest}>
          </img>
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