const bodyParser = require('body-parser')
const express = require('express')
const app = express()
const multer = require('multer'); // Pour l'upload d'images
const upload = multer(); // Ditto
const fs = require('fs'); // Ditto
const {v1: uuidv1} = require('uuid'); // Pour donner des identifiants uniques aux images
const port = 2022
var cors = require('cors');
const util = require('util');
const exec = util.promisify(require('child_process').exec);

app.use(bodyParser.urlencoded({ extended: false }))
app.use(bodyParser.json())

app.use(cors(({
    origin: '*'
})));

app.get('/', (req, res) => {
    res.status(404).send({})
})

async function executeScriptAI(filename) {
    // Si le programme renvoie 0 c'est dans le try si c'est un autre c'est dans le catch
    var res = 255
    try {
        await exec('python3 AI/main.py ' + filename)
        res = 0 // Le code de retour était 0 sil e programme a réussi
    } catch (error) {
        res = error.code
    }
    console.log(res)
    return res
};

app.post('/', (req, res) => {
    console.log("[POST] /")
    if (req.body.file != undefined) {
        console.log("[Image reçue]")
        filename = "img/" + uuidv1() + ".png"
        var data = req.body.file;
        data = data.replace(/^data:image\/png;base64,/, '');
        fs.writeFile(filename, data, 'base64', function(err) { if (err) throw err; });
        console.log(filename)
        executeScriptAI(filename).then((code) => { 
            if (code != 255) {
                res.status(200).send({'answer': code}).end()
            }else{
                res.status(500).send({'answer': 'Failed to process image'}).end()
            }
        });
    }else{
        res.status(400).send({'answer': 'No file passed'})
    }
})

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`)
})