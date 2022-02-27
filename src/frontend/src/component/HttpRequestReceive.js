import Cookies from 'js-cookie'


function HttpRequestReceive(type, cookie_nb) {
    var where_file = "https://test" + type + "_" + Cookies.get('UserNB');
    console.log(where_file);
    async function fetchMovies() {
        const response = await fetch("https://jsonplaceholder.typicode.com/todos/1");
        console.log(response);
    }

}


export default HttpRequestReceive