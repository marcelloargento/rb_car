Blockly.Blocks['car_avanti'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
    var imp=this.appendDummyInput();
    var image = new Blockly.FieldImage('img/avanti.png', 20, 20, '*');
    imp.appendField(image);
    imp.appendField('AVANTI');	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['car_indietro'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
    var imp=this.appendDummyInput();
    var image = new Blockly.FieldImage('img/indietro.png', 20, 20, '*');
    imp.appendField(image);
    imp.appendField('INDIETRO');	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['car_destra'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
    var imp=this.appendDummyInput();
    var image = new Blockly.FieldImage('img/destra.png', 20, 20, '*');
    imp.appendField(image);
    imp.appendField('DESTRA');	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['car_sinistra'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
    var imp=this.appendDummyInput();
    var image = new Blockly.FieldImage('img/sinistra.png', 20, 20, '*');
    imp.appendField(image);
    imp.appendField('SINISTRA');	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_wait'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
    this.appendValueInput("SECOND")
		.appendField('Aspetta ')
        .setCheck("Number");
	this.setInputsInline(true);
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_roar'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
	
	this.appendDummyInput()
		.appendField('ROAR');
	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_burp'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
	
	this.appendDummyInput()
		.appendField('BURP');
	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};

Blockly.Blocks['robosapien_peto'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
	
	this.appendDummyInput()
		.appendField('PETO');
	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_balla'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
	
	this.appendDummyInput()
		.appendField('BALLA');
	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_fermo'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
	
	this.appendDummyInput()
		.appendField('FERMO');
	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_braccio_destro_giu'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
	
	this.appendDummyInput()
		.appendField('BRACCIO DESTRO GIU');
	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_braccio_destro_su'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
	
	this.appendDummyInput()
		.appendField('BRACCIO DESTRO SU');
	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_braccio_sinistro_giu'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
	
	this.appendDummyInput()
		.appendField('BRACCIO SINISTRO GIU');
	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_braccio_sinistro_su'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
	
	this.appendDummyInput()
		.appendField('BRACCIO SINISTRO SU');
	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_passo_avanti'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
    var imp=this.appendDummyInput();
    var image = new Blockly.FieldImage('img/avanti.png', 20, 20, '*');
    imp.appendField(image);
    imp.appendField('PASSO AVANTI');	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_passo_indietro'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
    var imp=this.appendDummyInput();
    var image = new Blockly.FieldImage('img/indietro.png', 20, 20, '*');
    imp.appendField(image);
    imp.appendField('PASSO INDIETRO');	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_passo_destra'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
    var imp=this.appendDummyInput();
    var image = new Blockly.FieldImage('img/destra.png', 20, 20, '*');
    imp.appendField(image);
    imp.appendField('PASSO A DESTRA');	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};
Blockly.Blocks['robosapien_passo_sinistra'] = {
  init: function() {
    this.setHelpUrl('http://www.example.com/');
    this.setColour(20);
    var imp=this.appendDummyInput();
    var image = new Blockly.FieldImage('img/sinistra.png', 20, 20, '*');
    imp.appendField(image);
    imp.appendField('PASSO  A SINISTRA');	
    this.setPreviousStatement(true, "null");
    this.setNextStatement(true, "null");
    this.setTooltip('');
  }
};