import Cookies from 'js-cookie'


async function HttpRequestReceive(type) {
    var where_file = "https://test" + type + "_" + Cookies.get('UserNB');
    console.log(where_file);
    
    const response = await fetch("https://jsonplaceholder.typicode.com/todos/1");
    console.log(response);
    
    return where_file;
}


export default HttpRequestReceive