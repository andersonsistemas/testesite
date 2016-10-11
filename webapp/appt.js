var appt = angular.module('appt',['ngRoute']);
 
appt.config(function($routeProvider, $locationProvider)
{
   
   $routeProvider
 
   .when('/', {
      templateUrl : 'views/pedidosGarcom.html',
      controller  : 'listarPedidos',
   })
   
   .when('/cadastrar', {
      templateUrl : 'views/cadastrarPedido.html',
      controller  : 'alterarPedidos',
   }) 
   
   .when('/alterar', {
      templateUrl : 'views/alterarPedido.html',
      controller  : 'alterarPedidos',
   }) 
   
   .when('/pagamentos', {
      templateUrl : 'views/pagamentos.html',
      controller  : 'pagamentos',
   }) 
   
   .when('/receber', {
      templateUrl : 'views/recebimento.html',
      controller  : 'receber',
   }) 
   
   .when('/entregas', {
      templateUrl : 'views/entregas.html',
      controller  : 'entregas',
   }) 
   
   .when('/encaminharEntregas', {
      templateUrl : 'views/encaminharEntregas.html',
      controller  : 'encaminharEntregas',
   }) 
   
   .when('/encaminharEntregasConfirmacao', {
      templateUrl : 'views/encaminharEntregasConfirmacao.html',
      controller  : 'encaminharEntregasConfirmacao',
   }) 

   .when('/pedidosTelefonista', {
      templateUrl : 'views/pedidosTelefonista.html',
      controller  : 'telefonista',
   }) 
   
   .when('/cadastrarPedidosTelefonista', {
      templateUrl : 'views/cadastrarPedidosTelefonista.html',
      controller  : 'telefonista',
   }) 
   
   
   .when('/alterarPedidosTelefonista', {
      templateUrl : 'views/alterarPedidosTelefonista.html',
      controller  : 'telefonista',
   }) 
 
 
   // caso não seja nenhum desses, redirecione para a rota '/'
   .otherwise ({ redirectTo: '/' });
});
