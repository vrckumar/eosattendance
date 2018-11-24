// import { Api, JsonRpc, RpcError, JsSignatureProvider } from 'eosjs';

const { Api, JsonRpc, RpcError, JsSignatureProvider } = require('eosjs');

const fetch = require('node-fetch');

const { TextDecoder, TextEncoder } = require('text-encoding');

// const defaultPrivateKey = "5JtUScZK2XEp3g9gh7F8bwtPTRAkASmNrrftmx4AxDKD5K4zDnr"; // useraaaaaaaa
const defaultPrivateKey = "5KQwrPbwdL6PhXujxW37FSSQZ1JiwsST4cqQzDeyXtP79zkvFD3"; // useraaaaaaaa
const signatureProvider = new JsSignatureProvider([defaultPrivateKey]);
const rpc = new JsonRpc('http://127.0.0.1:7777', { fetch });
// const contractName = 'dmanpowertrk';
const contractName = 'manpowertrac';
const userName = 'manpowertrac';

const api = new Api({ rpc, signatureProvider, textDecoder: new TextDecoder(), textEncoder: new TextEncoder() });

async function fetchPeople() {

    // Main call to blockchain after setting action, account_name and data
    const result = await rpc.get_table_rows({
        "json": true,
        "code": contractName,    // contract who owns the table
        "scope": contractName,   // scope of the table
        "table": "people",    // name of the table as specified by the contract abi
        "limit": 100,
        "lower_bound": userName,
      });
      console.log(result);
  }

  fetchPeople();