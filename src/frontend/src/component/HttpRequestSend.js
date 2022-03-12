import axios from 'axios';
import Cookies from 'js-cookie'


function sendRequest(file_name, file){
    const formData = new FormData();
    formData.append(
      file_name,
      file,
      file.name
    );
    // L'url de notre server
    axios.post("localhost:2022", formData);
}

function HttpRequestSend(file_name, type, file) {
    var final_name = type + "_" + Cookies.get('UserNB') + "_" + file_name;
    sendRequest(final_name, file);
}
  
export default HttpRequestSend