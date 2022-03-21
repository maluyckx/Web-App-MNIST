async function HttpRequestSend(file) {
  return await fetch("http://127.0.0.1:2022/", {
    method: 'POST',
    headers: {
      'Accept': 'application/json',
      'Content-Type': 'application/json'
    },
    body: JSON.stringify({'file': file})
  }).then((res) => {return res.json()}).then((data) => {
    return data.answer
  })
  // console.log("[HTTP Receive] ", res)
  // return res
}
  
export default HttpRequestSend