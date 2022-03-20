import axios from 'axios';
import Cookies from 'js-cookie'


function sendRequest(file){
    fetch("http://127.0.0.1:2022/", {
      method: 'POST',
      headers: {
        'Accept': 'application/json',
        'Content-Type': 'application/json'
      },
      body: JSON.stringify({'file': file})
    }).then((res) => {return res.json()}).then((data) => {console.log(data.answer)})
}

function HttpRequestSend(file) {
    sendRequest(file);
}
  
export default HttpRequestSend