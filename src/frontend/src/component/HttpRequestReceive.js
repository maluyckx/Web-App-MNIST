import Cookies from 'js-cookie'


async function HttpRequestReceive(type) {
    var where_file = "localhost:2022/" + type + "_" + Cookies.get('UserNB');
    console.log(where_file);
    
    const response = await fetch(where_file);
    console.log(response);
    
    return where_file;
}


export default HttpRequestReceive