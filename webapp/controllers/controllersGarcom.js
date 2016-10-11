appt.controller('listarPedidos', function($rootScope, $location) {
		 
		   $rootScope.pedidos = [  {numero: 1, descricao: 'Arroz temperado', tempoEspera: '00:30:39', mesa: 13 },
					               {numero: 2, descricao: 'Feijoada', tempoEspera: '00:23:30', mesa: 34},
					               {numero: 3, descricao: 'Arroz branco e feijão tropeiro', tempoEspera: '00:18:40', mesa: 3},
					               {numero: 4, descricao: 'Suco de laranja', tempoEspera: '00:15:03', mesa: 4 },
					               {numero: 5, descricao: 'Vinho tinto', tempoEspera: '00:10:03', mesa: 10 }]
});

appt.controller('cadastrarPedidos', function($rootScope, $location) {
	   $rootScope.activetab = $location.path();
});

appt.controller('alterarPedidos', function($rootScope, $location) {
	   $rootScope.activetab = $location.path();
});

appt.controller('pagamentos', function($rootScope, $location) {
	   $rootScope.activetab = $location.path();
});

appt.controller('receber', function($rootScope, $location) {
	   $rootScope.activetab = $location.path();
});

appt.controller('entregas', function($rootScope, $location) {
	   $rootScope.activetab = $location.path();
});

appt.controller('encaminharEntregas', function($rootScope, $location) {
	   $rootScope.activetab = $location.path();
});

appt.controller('encaminharEntregasConfirmacao', function($rootScope, $location) {
	   $rootScope.activetab = $location.path();
});

appt.controller('telefonista', function($rootScope, $location) {
	   
});