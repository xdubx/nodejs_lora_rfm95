const rfm95 = require('./build/Release/rfm95');

const modemConfigs = rfm95.getModemConfigs();
console.log(rfm95.getModemConfigs());
//console.log(modemConfigs.Bw125Cr45Sf128);

rfm95.init()
  .then((msg) => {
    console.log(msg)
  })
  .catch ((err) => {
    console.error('failed: ' + err)
  })
;

var promise = rfm95.sleep();
promise.then(console.log, console.error);
console.log("Running...");

// rfm95.setModemConfig(modemConfigs.Bw125Cr45Sf128)
//   .then(console.log, console.error);


rfm95.standby()
  .then(function (msg) {
      console.log(msg)
  })
  .catch (function (err) {
      console.error('failed: ' + err)
  });

rfm95.listen()
  .then(function (msg) {
      console.log(msg)
  })
  .catch (function (err) {
      console.error('failed: ' + err)
  });