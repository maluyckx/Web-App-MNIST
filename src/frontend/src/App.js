import './App.css';
import React from "react";
import {
  BrowserRouter,
  Routes,
  Route
} from "react-router-dom";

import DrawSimple from "./component/DrawSimple/DrawSimple"
import Home from './component/Home/Home';
import MainGame from './component/Game/MainGame';
import ImageMain from './component/Image/ImageMain';
import Header from './component/Header';
import Team from './component/Team';

function App() {
  return (
    <div className="App">
      <BrowserRouter>
        <header className="App-header">
          <Header/>
        </header>
        <body>
          <div className='Main-App'>
              <Routes>
                <Route path="/game" element={<MainGame />} /> 
                <Route path="/draw" element={<DrawSimple />} /> 
                <Route path="/image" element={<ImageMain />} /> 
                <Route path="/team" element={<Team />} /> 
                <Route path="/" element={<Home />} /> 
              </Routes>
          </div>
        </body>
        </BrowserRouter>
    </div>
  );
}

export default App;
