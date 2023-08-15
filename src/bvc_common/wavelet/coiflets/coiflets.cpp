#include "coiflets.h"

std::vector<double> coiflets1::lo_d = { -0.01565572813546454, -0.0727326195128539, 0.38486484686420286, 0.8525720202122554, 0.3378976624578092, -0.0727326195128539 };
std::vector<double> coiflets1::hi_d = { 0.0727326195128539, 0.3378976624578092, -0.8525720202122554, 0.38486484686420286, 0.0727326195128539, -0.01565572813546454 };
std::vector<double> coiflets1::lo_r = { -0.0727326195128539, 0.3378976624578092, 0.8525720202122554, 0.38486484686420286, -0.0727326195128539, -0.01565572813546454 };
std::vector<double> coiflets1::hi_r = { -0.01565572813546454, 0.0727326195128539, 0.38486484686420286, -0.8525720202122554, 0.3378976624578092, 0.0727326195128539 };

std::vector<double> coiflets2::lo_d = { -0.0007205494453645122, -0.0018232088707029932, 0.0056114348193944995, 0.023680171946334084, -0.0594344186464569, -0.0764885990783064, 0.41700518442169254, 0.8127236354455423, 0.3861100668211622, -0.06737255472196302, -0.04146493678175915, 0.016387336463522112 };
std::vector<double> coiflets2::hi_d = { -0.016387336463522112, -0.04146493678175915, 0.06737255472196302, 0.3861100668211622, -0.8127236354455423, 0.41700518442169254, 0.0764885990783064, -0.0594344186464569, -0.023680171946334084, 0.0056114348193944995, 0.0018232088707029932, -0.0007205494453645122 };
std::vector<double> coiflets2::lo_r = { 0.016387336463522112, -0.04146493678175915, -0.06737255472196302, 0.3861100668211622, 0.8127236354455423, 0.41700518442169254, -0.0764885990783064, -0.0594344186464569, 0.023680171946334084, 0.0056114348193944995, -0.0018232088707029932, -0.0007205494453645122 };
std::vector<double> coiflets2::hi_r = { -0.0007205494453645122, 0.0018232088707029932, 0.0056114348193944995, -0.023680171946334084, -0.0594344186464569, 0.0764885990783064, 0.41700518442169254, -0.8127236354455423, 0.3861100668211622, 0.06737255472196302, -0.04146493678175915, -0.016387336463522112 };

std::vector<double> coiflets3::lo_d = { -3.459977283621256e-05, -7.098330313814125e-05, 0.0004662169601128863, 0.0011175187708906016, -0.0025745176887502236, -0.00900797613666158, 0.015880544863615904, 0.03455502757306163, -0.08230192710688598, -0.07179982161931202, 0.42848347637761874, 0.7937772226256206, 0.4051769024096169, -0.06112339000267287, -0.0657719112818555, 0.023452696141836267, 0.007782596427325418, -0.003793512864491014 };
std::vector<double> coiflets3::hi_d = { 0.003793512864491014, 0.007782596427325418, -0.023452696141836267, -0.0657719112818555, 0.06112339000267287, 0.4051769024096169, -0.7937772226256206, 0.42848347637761874, 0.07179982161931202, -0.08230192710688598, -0.03455502757306163, 0.015880544863615904, 0.00900797613666158, -0.0025745176887502236, -0.0011175187708906016, 0.0004662169601128863, 7.098330313814125e-05, -3.459977283621256e-05 };
std::vector<double> coiflets3::lo_r = { -0.003793512864491014, 0.007782596427325418, 0.023452696141836267, -0.0657719112818555, -0.06112339000267287, 0.4051769024096169, 0.7937772226256206, 0.42848347637761874, -0.07179982161931202, -0.08230192710688598, 0.03455502757306163, 0.015880544863615904, -0.00900797613666158, -0.0025745176887502236, 0.0011175187708906016, 0.0004662169601128863, -7.098330313814125e-05, -3.459977283621256e-05 };
std::vector<double> coiflets3::hi_r = { -3.459977283621256e-05, 7.098330313814125e-05, 0.0004662169601128863, -0.0011175187708906016, -0.0025745176887502236, 0.00900797613666158, 0.015880544863615904, -0.03455502757306163, -0.08230192710688598, 0.07179982161931202, 0.42848347637761874, -0.7937772226256206, 0.4051769024096169, 0.06112339000267287, -0.0657719112818555, -0.023452696141836267, 0.007782596427325418, 0.003793512864491014 };

std::vector<double> coiflets4::lo_d = { -1.7849850030882614e-06, -3.2596802368833675e-06, 3.1229875865345646e-05, 6.233903446100713e-05, -0.00025997455248771324, -0.0005890207562443383, 0.0012665619292989445, 0.003751436157278457, -0.00565828668661072, -0.015211731527946259, 0.025082261844864097, 0.03933442712333749, -0.09622044203398798, -0.06662747426342504, 0.4343860564914685, 0.782238930920499, 0.41530840703043026, -0.05607731331675481, -0.08126669968087875, 0.026682300156053072, 0.016068943964776348, -0.0073461663276420935, -0.0016294920126017326, 0.0008923136685823146 };
std::vector<double> coiflets4::hi_d = { -0.0008923136685823146, -0.0016294920126017326, 0.0073461663276420935, 0.016068943964776348, -0.026682300156053072, -0.08126669968087875, 0.05607731331675481, 0.41530840703043026, -0.782238930920499, 0.4343860564914685, 0.06662747426342504, -0.09622044203398798, -0.03933442712333749, 0.025082261844864097, 0.015211731527946259, -0.00565828668661072, -0.003751436157278457, 0.0012665619292989445, 0.0005890207562443383, -0.00025997455248771324, -6.233903446100713e-05, 3.1229875865345646e-05, 3.2596802368833675e-06, -1.7849850030882614e-06 };
std::vector<double> coiflets4::lo_r = { 0.0008923136685823146, -0.0016294920126017326, -0.0073461663276420935, 0.016068943964776348, 0.026682300156053072, -0.08126669968087875, -0.05607731331675481, 0.41530840703043026, 0.782238930920499, 0.4343860564914685, -0.06662747426342504, -0.09622044203398798, 0.03933442712333749, 0.025082261844864097, -0.015211731527946259, -0.00565828668661072, 0.003751436157278457, 0.0012665619292989445, -0.0005890207562443383, -0.00025997455248771324, 6.233903446100713e-05, 3.1229875865345646e-05, -3.2596802368833675e-06, -1.7849850030882614e-06 };
std::vector<double> coiflets4::hi_r = { -1.7849850030882614e-06, 3.2596802368833675e-06, 3.1229875865345646e-05, -6.233903446100713e-05, -0.00025997455248771324, 0.0005890207562443383, 0.0012665619292989445, -0.003751436157278457, -0.00565828668661072, 0.015211731527946259, 0.025082261844864097, -0.03933442712333749, -0.09622044203398798, 0.06662747426342504, 0.4343860564914685, -0.782238930920499, 0.41530840703043026, 0.05607731331675481, -0.08126669968087875, -0.026682300156053072, 0.016068943964776348, 0.0073461663276420935, -0.0016294920126017326, -0.0008923136685823146 };

std::vector<double> coiflets5::lo_d = { -9.517657273819165e-08, -1.6744288576823017e-07, 2.0637618513646814e-06, 3.7346551751414047e-06, -2.1315026809955787e-05, -4.134043227251251e-05, 0.00014054114970203437, 0.00030225958181306315, -0.0006381313430451114, -0.0016628637020130838, 0.0024333732126576722, 0.006764185448053083, -0.009164231162481846, -0.01976177894257264, 0.03268357426711183, 0.0412892087501817, -0.10557420870333893, -0.06203596396290357, 0.4379916261718371, 0.7742896036529562, 0.4215662066908515, -0.05204316317624377, -0.09192001055969624, 0.02816802897093635, 0.023408156785839195, -0.010131117519849788, -0.004159358781386048, 0.0021782363581090178, 0.00035858968789573785, -0.00021208083980379827 };
std::vector<double> coiflets5::hi_d = { 0.00021208083980379827, 0.00035858968789573785, -0.0021782363581090178, -0.004159358781386048, 0.010131117519849788, 0.023408156785839195, -0.02816802897093635, -0.09192001055969624, 0.05204316317624377, 0.4215662066908515, -0.7742896036529562, 0.4379916261718371, 0.06203596396290357, -0.10557420870333893, -0.0412892087501817, 0.03268357426711183, 0.01976177894257264, -0.009164231162481846, -0.006764185448053083, 0.0024333732126576722, 0.0016628637020130838, -0.0006381313430451114, -0.00030225958181306315, 0.00014054114970203437, 4.134043227251251e-05, -2.1315026809955787e-05, -3.7346551751414047e-06, 2.0637618513646814e-06, 1.6744288576823017e-07, -9.517657273819165e-08 };
std::vector<double> coiflets5::lo_r = { -0.00021208083980379827, 0.00035858968789573785, 0.0021782363581090178, -0.004159358781386048, -0.010131117519849788, 0.023408156785839195, 0.02816802897093635, -0.09192001055969624, -0.05204316317624377, 0.4215662066908515, 0.7742896036529562, 0.4379916261718371, -0.06203596396290357, -0.10557420870333893, 0.0412892087501817, 0.03268357426711183, -0.01976177894257264, -0.009164231162481846, 0.006764185448053083, 0.0024333732126576722, -0.0016628637020130838, -0.0006381313430451114, 0.00030225958181306315, 0.00014054114970203437, -4.134043227251251e-05, -2.1315026809955787e-05, 3.7346551751414047e-06, 2.0637618513646814e-06, -1.6744288576823017e-07, -9.517657273819165e-08 };
std::vector<double> coiflets5::hi_r = { -9.517657273819165e-08, 1.6744288576823017e-07, 2.0637618513646814e-06, -3.7346551751414047e-06, -2.1315026809955787e-05, 4.134043227251251e-05, 0.00014054114970203437, -0.00030225958181306315, -0.0006381313430451114, 0.0016628637020130838, 0.0024333732126576722, -0.006764185448053083, -0.009164231162481846, 0.01976177894257264, 0.03268357426711183, -0.0412892087501817, -0.10557420870333893, 0.06203596396290357, 0.4379916261718371, -0.7742896036529562, 0.4215662066908515, 0.05204316317624377, -0.09192001055969624, -0.02816802897093635, 0.023408156785839195, 0.010131117519849788, -0.004159358781386048, -0.0021782363581090178, 0.00035858968789573785, 0.00021208083980379827 };
