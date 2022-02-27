import axios from 'axios';
import { useCookies } from 'react-cookie';


function sendRequest(file_name, file){
    const formData = new FormData();
    formData.append(
      file_name,
      file,
      file.name
    );
    // L'url de notre server
    axios.post("https://eo4vmpnu218dpco.m.pipedream.net/", formData);
}

function HttpRequestSend(file_name, type, file) {
    const [cookies, _] = useCookies(["user"]);
    var final_name = type + "_" + cookies.UserNB + "_" + file_name;
    sendRequest(final_name, file);
}
  
export default HttpRequestSend