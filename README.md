Tareas a realizar:
    1. Desarrollar el código (claves.c) que gestiona el almacenamiento y procesamiento de las tuplas.
    Puede elegirse la estructura de datos que se estime oportuna, siempre que no imponga un límite en el número de elementos que se pueden almacenar.

    2. Desarrollar el código del servidor (servidor-mq.c) encargado de las comunicaciones con la parte cliente. Este servidor debe ser concurrente, recibirá las peticiones del lado cliente e invocará a las funciones implementadas en claves.c.

    3. Desarrollar el código que implementa el código (proxy-mq.c) de las llamadas anteriores (destroy, set_value, get_value, delete_key, modify_value y exist) en el lado del cliente. Este código suplanta a las funciones de la API y se encarga de realizar las peticiones al servidor. Es decir, este es el código que ofrece la interfaz a los clientes y se encarga de implementar los servicios anteriores (del lado del cliente) contactando con el servidor anterior.
    A partir de dicha implementación se deberá crear una biblioteca dinámica denominada libclaves.so. 
    Esta será la biblioteca que utilizarán las aplicaciones de usuario para usar el servicio. Debe investigar y buscar la forma de crear dicha biblioteca.

    4. Desarrollar un ejemplo de código de un cliente (app-cliente.c) que utilice las funciones anteriores. El ejecutable de este programa tiene que generarse empleando la biblioteca desarrollada en el apartado anterior, es decir, el código de este cliente debe enlazarse con la biblioteca dinámica anterior. Este cliente se utilizará para probar el servicio desarrollado y deberá realizar las invocaciones a la API de tuplas que consideren oportunas. El código incluido en app-cliente.c solo podrá incluir llamadas a los servicios implementados y descritos anteriormente. En él no puede haber ninguna referencia a colas de mensajes.

    5. Elaborar un plan de pruebas del servicio desarrollado. Este plan se probará con el código desarrollado en el apartado anterior, es decir en app-cliente.c. Se pueden entregar distintos ejemplos de aplicación cliente dependiendo del plan de pruebas elaborado.