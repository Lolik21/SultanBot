const { execSync } = require('child_process');
const path = require('path');
const fs = require('fs');
const glob = require('glob');

const unluac = path.resolve('..', 'unluac.jar');
console.log(`Path to unluac: ${unluac}`);

const unluacCommand = `java -jar ${unluac}`;

const outputFolder = path.resolve('..', '..', 'lua-d-unluac');
if (!fs.existsSync(outputFolder)) {
    fs.mkdirSync(outputFolder);
}
console.log(`Output folder: ${outputFolder}`);

const inputFolder = path.resolve('..', '..', 'lua-bytecode');
if (!fs.existsSync(inputFolder)) {
    console.error('The lua-bytecode is not extracted from resources! Run "lua-unpack"');
    process.exit(-1);
}

glob(`${inputFolder}/*.lu`, (err, matches) => {
    matches.forEach(match => {
        const fileName = match.slice(match.lastIndexOf('/') + 1);
        try {
            console.log(`Decompiling ${match}`);
            execSync(`${unluacCommand} ${match} > ${outputFolder}/${fileName}a`, { stdio: 'ignore' });
        } catch {}
    });
});
