const { execSync, execFileSync } = require('child_process');
const path = require('path');
const fs = require('fs');

const outputFile = path.resolve('..', '..', 'apk', 'com.dc.hwsj', 'assets', 'resource.car');
console.log(`Input File: ${outputFile}`);

const inputDir = path.resolve('..', '..', 'lua-bytecode');
if (!fs.existsSync(inputDir)) {
    fs.mkdirSync(inputDir);
}
console.log(`Output Dir: ${inputDir}`);

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
    console.log('Packaging......');
    execSync(`py ${coronaArchiver} -p "${inputDir}" "${outputFile}"`)
    console.log('Done.');
} catch(error) {
    console.error(error);
}