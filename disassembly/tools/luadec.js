const { execSync } = require('child_process');
const path = require('path');
const fs = require('fs');

const luadec = path.resolve('tools', 'luadec.exe');
console.log(`Path to luadec.exe: ${luadec}`);

const outputFolder = 'lua-d-luadec';
if (!fs.existsSync(outputFolder)) {
    fs.mkdirSync(outputFolder);
}
console.log(`Output folder: ${outputFolder}`);

const inputFolder = 'lua-unpacked';
if (!fs.existsSync(inputFolder)) {
    console.error('The lua-bytecode is not extracted from resources! Run "lua-unpack"');
    process.exit(-1);
}

fs.readdir(inputFolder, (err, matches) => {
    matches.forEach(match => {
        const fileName = match.slice(match.lastIndexOf('/') + 1);
        try {
            console.log(`Decompiling ${match}`);
            execSync(`${luadec} ${match} > ${outputFolder}/${fileName}a`, { stdio: 'ignore' });
        } catch {}
    });
});
