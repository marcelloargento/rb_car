Blockly.JavaScript['car_avanti'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code ='callServer(\'avanti.py\');';
  return code;
};
Blockly.JavaScript['car_indietro'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code ='callServer(\'indietro.py\');';
  return code;
};
Blockly.JavaScript['car_sinistra'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code ='callServer(\'sinistra.py\');';
  return code;
};
Blockly.JavaScript['car_destra'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code ='callServer(\'destra.py\');';
  return code;
};

Blockly.JavaScript['robosapien_burp'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code ='callServer(\'BURP.sh\');';
  return code;
};

Blockly.JavaScript['robosapien_roar'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code ='callServer(\'ROAR.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_peto'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = 'callServer(\'PETO.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_balla'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = 'callServer(\'BALLA.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_fermo'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = 'callServer(\'FERMO.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_braccio_destro_giu'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = 'callServer(\'BRACCIO-DESTRO-GIU.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_braccio_destro_su'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = 'callServer(\'BRACCIO-DESTRO-SU.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_braccio_sinistro_giu'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = 'callServer(\'BRACCIO-SINISTRO-GIU.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_braccio_sinistro_su'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = 'callServer(\'BRACCIO-SINISTRO-SU.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_passo_avanti'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = 'callServer(\'PASSO-AVANTI.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_passo_indietro'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = 'callServer(\'PASSO-INDIETRO.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_passo_destra'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = 'callServer(\'PASSO-DESTRA.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_passo_sinistra'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  var code = 'callServer(\'PASSO-SINISTRA.sh\');';
  return code;
};
Blockly.JavaScript['robosapien_wait'] = function(block) {
  // TODO: Assemble JavaScript into code variable.
  
  var p=Blockly.JavaScript.valueToCode(block, 'SECOND', Blockly.JavaScript.ORDER_ADDITION) || '0'
  var code = 'callServer(\'WAIT.sh?p1='+p+'\');';
  
  return code;
};
