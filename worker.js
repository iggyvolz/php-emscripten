/**
 * 
 */

importScripts("php.js");

const stdoutCallback = (data) => {
    const str = Array.from(data).map(x => String.fromCharCode(x)).join('')
    postMessage({data, str});
}

const ready = new Promise(r => Module.onRuntimeInitialized = r);
onmessage = async e => {
    const data = e.data;
    if(data.jsonrpc !== "2.0") {
        throw "Must be JSON RPC data";
    }
    console.log({worker: true, data});
    await ready;
    const response = Module.ccall('run_php', 'number', ['string'], [data], {async: true});
    console.log({response});
}