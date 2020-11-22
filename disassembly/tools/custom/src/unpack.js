const { execSync, execFileSync } = require('child_process');
const path = require('path');
const fs = require('fs');

const inputFile = path.resolve('..', '..', 'apk', 'com.dc.hwsj', 'assets', 'resource.car');
console.log(`Input File: ${inputFile}`);

const outPutDir = path.resolve('..', '..', 'lua-bytecode');
if (!fs.existsSync(outPutDir)) {
    fs.mkdirSync(outPutDir);
}
console.log(`Output Dir: ${outPutDir}`);

const coronaArchiver = path.resolve('..', 'corona-archiver', 'corona-archiver.py')
console.log(`Corona Archiver: ${coronaArchiver}`);

console.log(`Checking pyton...`);

try {
    execFileSync('py');
    console.log(`Pyton is installed!`);
} catch {
    console.log('Install pyton! And try again');
}

try {
    console.log('Unpacking......');
    execSync(`py ${coronaArchiver} -u "${inputFile}" "${outPutDir}"`)
    console.log('Done.');
} catch(error) {
    console.error(error);
}