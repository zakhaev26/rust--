const http = require('http');
const https = require('https');

const server = http.createServer((req, res) => {
    const url = 'https://v2.jokeapi.dev/joke/Programming,Dark?type=single';

    https.get(url, (response) => {
        let data = '';

        response.on('data', (chunk) => {
            data += chunk;
        });

        response.on('end', () => {
            console.log(data);
            res.writeHead(200, {'Content-Type': 'application/json'});
            res.end(data);
        });
    }).on('error', (error) => {
        console.error(`Error: ${error.message}`);
        res.writeHead(500, {'Content-Type': 'text/plain'});
        res.end('Internal Server Error');
    });
});

const PORT = 8080;

server.listen(PORT, () => {
    console.clear();
    console.log(`Server is running at http://localhost:${PORT}`);
});
