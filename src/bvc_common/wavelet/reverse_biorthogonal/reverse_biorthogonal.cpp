#include "bvc_common/wavelet/reverse_biorthogonal/reverse_biorthogonal.h"

std::vector<double> reverse_biorthogonal1p1::lo_d = { 0.7071067811865476, 0.7071067811865476 };
std::vector<double> reverse_biorthogonal1p1::hi_d = { -0.7071067811865476, 0.7071067811865476 };
std::vector<double> reverse_biorthogonal1p1::lo_r = { 0.7071067811865476, 0.7071067811865476 };
std::vector<double> reverse_biorthogonal1p1::hi_r = { 0.7071067811865476, -0.7071067811865476 };

std::vector<double> reverse_biorthogonal1p3::lo_d = { 0.0, 0.0, 0.7071067811865476, 0.7071067811865476, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal1p3::hi_d = { 0.08838834764831845, 0.08838834764831845, -0.7071067811865476, 0.7071067811865476, -0.08838834764831845, -0.08838834764831845 };
std::vector<double> reverse_biorthogonal1p3::lo_r = { -0.08838834764831845, 0.08838834764831845, 0.7071067811865476, 0.7071067811865476, 0.08838834764831845, -0.08838834764831845 };
std::vector<double> reverse_biorthogonal1p3::hi_r = { 0.0, 0.0, 0.7071067811865476, -0.7071067811865476, 0.0, 0.0 };

std::vector<double> reverse_biorthogonal1p5::lo_d = { 0.0, 0.0, 0.0, 0.0, 0.7071067811865476, 0.7071067811865476, 0.0, 0.0, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal1p5::hi_d = { -0.01657281518405971, -0.01657281518405971, 0.12153397801643787, 0.12153397801643787, -0.7071067811865476, 0.7071067811865476, -0.12153397801643787, -0.12153397801643787, 0.01657281518405971, 0.01657281518405971 };
std::vector<double> reverse_biorthogonal1p5::lo_r = { 0.01657281518405971, -0.01657281518405971, -0.12153397801643787, 0.12153397801643787, 0.7071067811865476, 0.7071067811865476, 0.12153397801643787, -0.12153397801643787, -0.01657281518405971, 0.01657281518405971 };
std::vector<double> reverse_biorthogonal1p5::hi_r = { 0.0, 0.0, 0.0, 0.0, 0.7071067811865476, -0.7071067811865476, 0.0, 0.0, 0.0, 0.0 };

std::vector<double> reverse_biorthogonal2p2::lo_d = { 0.0, 0.0, 0.3535533905932738, 0.7071067811865476, 0.3535533905932738, 0.0 };
std::vector<double> reverse_biorthogonal2p2::hi_d = { 0.1767766952966369, 0.3535533905932738, -1.0606601717798214, 0.3535533905932738, 0.1767766952966369, 0.0 };
std::vector<double> reverse_biorthogonal2p2::lo_r = { -0.1767766952966369, 0.3535533905932738, 1.0606601717798214, 0.3535533905932738, -0.1767766952966369, 0.0 };
std::vector<double> reverse_biorthogonal2p2::hi_r = { 0.0, 0.0, 0.3535533905932738, -0.7071067811865476, 0.3535533905932738, 0.0 };

std::vector<double> reverse_biorthogonal2p4::lo_d = { 0.0, 0.0, 0.0, 0.0, 0.3535533905932738, 0.7071067811865476, 0.3535533905932738, 0.0, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal2p4::hi_d = { -0.03314563036811942, -0.06629126073623884, 0.1767766952966369, 0.4198446513295126, -0.9943689110435825, 0.4198446513295126, 0.1767766952966369, -0.06629126073623884, -0.03314563036811942, 0.0 };
std::vector<double> reverse_biorthogonal2p4::lo_r = { 0.03314563036811942, -0.06629126073623884, -0.1767766952966369, 0.4198446513295126, 0.9943689110435825, 0.4198446513295126, -0.1767766952966369, -0.06629126073623884, 0.03314563036811942, 0.0 };
std::vector<double> reverse_biorthogonal2p4::hi_r = { 0.0, 0.0, 0.0, 0.0, 0.3535533905932738, -0.7071067811865476, 0.3535533905932738, 0.0, 0.0, 0.0 };

std::vector<double> reverse_biorthogonal2p6::lo_d = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3535533905932738, 0.7071067811865476, 0.3535533905932738, 0.0, 0.0, 0.0, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal2p6::hi_d = { 0.006905339660024878, 0.013810679320049757, -0.046956309688169176, -0.10772329869638811, 0.16987135563661201, 0.4474660099696121, -0.966747552403483, 0.4474660099696121, 0.16987135563661201, -0.10772329869638811, -0.046956309688169176, 0.013810679320049757, 0.006905339660024878, 0.0 };
std::vector<double> reverse_biorthogonal2p6::lo_r = { -0.006905339660024878, 0.013810679320049757, 0.046956309688169176, -0.10772329869638811, -0.16987135563661201, 0.4474660099696121, 0.966747552403483, 0.4474660099696121, -0.16987135563661201, -0.10772329869638811, 0.046956309688169176, 0.013810679320049757, -0.006905339660024878, 0.0 };
std::vector<double> reverse_biorthogonal2p6::hi_r = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3535533905932738, -0.7071067811865476, 0.3535533905932738, 0.0, 0.0, 0.0, 0.0, 0.0 };

std::vector<double> reverse_biorthogonal2p8::lo_d = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3535533905932738, 0.7071067811865476, 0.3535533905932738, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal2p8::hi_d = { -0.0015105430506304422, -0.0030210861012608843, 0.012947511862546647, 0.02891610982635418, -0.052998481890690945, -0.13491307360773608, 0.16382918343409025, 0.4625714404759166, -0.9516421218971786, 0.4625714404759166, 0.16382918343409025, -0.13491307360773608, -0.052998481890690945, 0.02891610982635418, 0.012947511862546647, -0.0030210861012608843, -0.0015105430506304422, 0.0 };
std::vector<double> reverse_biorthogonal2p8::lo_r = { 0.0015105430506304422, -0.0030210861012608843, -0.012947511862546647, 0.02891610982635418, 0.052998481890690945, -0.13491307360773608, -0.16382918343409025, 0.4625714404759166, 0.9516421218971786, 0.4625714404759166, -0.16382918343409025, -0.13491307360773608, 0.052998481890690945, 0.02891610982635418, -0.012947511862546647, -0.0030210861012608843, 0.0015105430506304422, 0.0 };
std::vector<double> reverse_biorthogonal2p8::hi_r = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3535533905932738, -0.7071067811865476, 0.3535533905932738, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

std::vector<double> reverse_biorthogonal3p1::lo_d = { 0.1767766952966369, 0.5303300858899107, 0.5303300858899107, 0.1767766952966369 };
std::vector<double> reverse_biorthogonal3p1::hi_d = { 0.3535533905932738, 1.0606601717798214, -1.0606601717798214, -0.3535533905932738 };
std::vector<double> reverse_biorthogonal3p1::lo_r = { -0.3535533905932738, 1.0606601717798214, 1.0606601717798214, -0.3535533905932738 };
std::vector<double> reverse_biorthogonal3p1::hi_r = { 0.1767766952966369, -0.5303300858899107, 0.5303300858899107, -0.1767766952966369 };

std::vector<double> reverse_biorthogonal3p3::lo_d = { 0.0, 0.0, 0.1767766952966369, 0.5303300858899107, 0.5303300858899107, 0.1767766952966369, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal3p3::hi_d = { -0.06629126073623884, -0.19887378220871652, 0.15467960838455727, 0.9943689110435825, -0.9943689110435825, -0.15467960838455727, 0.19887378220871652, 0.06629126073623884 };
std::vector<double> reverse_biorthogonal3p3::lo_r = { 0.06629126073623884, -0.19887378220871652, -0.15467960838455727, 0.9943689110435825, 0.9943689110435825, -0.15467960838455727, -0.19887378220871652, 0.06629126073623884 };
std::vector<double> reverse_biorthogonal3p3::hi_r = { 0.0, 0.0, 0.1767766952966369, -0.5303300858899107, 0.5303300858899107, -0.1767766952966369, 0.0, 0.0 };

std::vector<double> reverse_biorthogonal3p5::lo_d = { 0.0, 0.0, 0.0, 0.0, 0.1767766952966369, 0.5303300858899107, 0.5303300858899107, 0.1767766952966369, 0.0, 0.0, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal3p5::hi_d = { 0.013810679320049757, 0.04143203796014927, -0.052480581416189075, -0.26792717880896527, 0.07181553246425874, 0.966747552403483, -0.966747552403483, -0.07181553246425874, 0.26792717880896527, 0.052480581416189075, -0.04143203796014927, -0.013810679320049757 };
std::vector<double> reverse_biorthogonal3p5::lo_r = { -0.013810679320049757, 0.04143203796014927, 0.052480581416189075, -0.26792717880896527, -0.07181553246425874, 0.966747552403483, 0.966747552403483, -0.07181553246425874, -0.26792717880896527, 0.052480581416189075, 0.04143203796014927, -0.013810679320049757 };
std::vector<double> reverse_biorthogonal3p5::hi_r = { 0.0, 0.0, 0.0, 0.0, 0.1767766952966369, -0.5303300858899107, 0.5303300858899107, -0.1767766952966369, 0.0, 0.0, 0.0, 0.0 };

std::vector<double> reverse_biorthogonal3p7::lo_d = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1767766952966369, 0.5303300858899107, 0.5303300858899107, 0.1767766952966369, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal3p7::hi_d = { -0.0030210861012608843, -0.009063258303782653, 0.01683176542131064, 0.074663985074019, -0.03133297870736289, -0.301159125922835, 0.026499240945345472, 0.9516421218971786, -0.9516421218971786, -0.026499240945345472, 0.301159125922835, 0.03133297870736289, -0.074663985074019, -0.01683176542131064, 0.009063258303782653, 0.0030210861012608843 };
std::vector<double> reverse_biorthogonal3p7::lo_r = { 0.0030210861012608843, -0.009063258303782653, -0.01683176542131064, 0.074663985074019, 0.03133297870736289, -0.301159125922835, -0.026499240945345472, 0.9516421218971786, 0.9516421218971786, -0.026499240945345472, -0.301159125922835, 0.03133297870736289, 0.074663985074019, -0.01683176542131064, -0.009063258303782653, 0.0030210861012608843 };
std::vector<double> reverse_biorthogonal3p7::hi_r = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1767766952966369, -0.5303300858899107, 0.5303300858899107, -0.1767766952966369, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

std::vector<double> reverse_biorthogonal3p9::lo_d = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1767766952966369, 0.5303300858899107, 0.5303300858899107, 0.1767766952966369, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal3p9::hi_d = { 0.000679744372783699, 0.002039233118351097, -0.005060319219611981, -0.020618912641105536, 0.014112787930175846, 0.09913478249423216, -0.012300136269419315, -0.32019196836077857, -0.0020500227115698858, 0.9421257006782068, -0.9421257006782068, 0.0020500227115698858, 0.32019196836077857, 0.012300136269419315, -0.09913478249423216, -0.014112787930175846, 0.020618912641105536, 0.005060319219611981, -0.002039233118351097, -0.000679744372783699 };
std::vector<double> reverse_biorthogonal3p9::lo_r = { -0.000679744372783699, 0.002039233118351097, 0.005060319219611981, -0.020618912641105536, -0.014112787930175846, 0.09913478249423216, 0.012300136269419315, -0.32019196836077857, 0.0020500227115698858, 0.9421257006782068, 0.9421257006782068, 0.0020500227115698858, -0.32019196836077857, 0.012300136269419315, 0.09913478249423216, -0.014112787930175846, -0.020618912641105536, 0.005060319219611981, 0.002039233118351097, -0.000679744372783699 };
std::vector<double> reverse_biorthogonal3p9::hi_r = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.1767766952966369, -0.5303300858899107, 0.5303300858899107, -0.1767766952966369, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

std::vector<double> reverse_biorthogonal4p4::lo_d = { 0.0, 0.0, -0.06453888262869706, -0.04068941760916406, 0.41809227322161724, 0.7884856164055829, 0.41809227322161724, -0.04068941760916406, -0.06453888262869706, 0.0 };
std::vector<double> reverse_biorthogonal4p4::hi_d = { -0.03782845550726404, -0.023849465019556843, 0.11062440441843718, 0.37740285561283066, -0.8526986790088938, 0.37740285561283066, 0.11062440441843718, -0.0238494650156843, -0.03782845550726404, 0.0 };
std::vector<double> reverse_biorthogonal4p4::lo_r = { 0.03782845550726404, -0.023849465019556843, -0.11062440441843718, 0.37740285561283066, 0.8526986790088938, 0.37740285561283066, -0.11062440441843718, -0.023849465019556843, 0.03782845550726404, 0.0 };
std::vector<double> reverse_biorthogonal4p4::hi_r = { 0.0, 0.0, -0.06453888262869706, 0.04068941760916406, 0.41809227322161724, -0.7884856164055829, 0.41809227322161724, 0.04068941760916406, -0.06453888262869706, 0.0 };

std::vector<double> reverse_biorthogonal5p5::lo_d = { 0.0, 0.013456709459118716, -0.002694966880111507, -0.13670658466432914, -0.09350469740093886, 0.47680326579848425, 0.8995061097486484, 0.47680326579848425, -0.09350469740093886, -0.13670658466432914, -0.002694966880111507, 0.013456709459118716 };
std::vector<double> reverse_biorthogonal5p5::hi_d = { 0.0, 0.03968708834740544, -0.007948108637240322, -0.05446378846823691, -0.34560528195603346, 0.7366601814282105, -0.34560528195603346, -0.05446378846823691, -0.007948108637240322, 0.03968708834740544, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal5p5::lo_r = { 0.0, 0.03968708834740544, 0.007948108637240322, -0.05446378846823691, 0.34560528195603346, 0.7366601814282105, 0.34560528195603346, -0.05446378846823691, 0.007948108637240322, 0.03968708834740544, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal5p5::hi_r = { 0.0, -0.013456709459118716, -0.002694966880111507, 0.13670658466432914, -0.09350469740093886, -0.47680326579848425, 0.8995061097486484, -0.47680326579848425, -0.09350469740093886, 0.13670658466432914, -0.002694966880111507, -0.013456709459118716 };

std::vector<double> reverse_biorthogonal6p8::lo_d = { 0.0, 0.0, 0.0, 0.0, 0.014426282505624435, 0.014467504896790148, -0.07872200106262882, -0.04036797903033992, 0.41784910915027457, 0.7589077294536541, 0.41784910915027457, -0.04036797903033992, -0.07872200106262882, 0.014467504896790148, 0.014426282505624435, 0.0, 0.0, 0.0 };
std::vector<double> reverse_biorthogonal6p8::hi_d = { -0.0019088317364812906, -0.0019142861290887667, 0.016990639867602342, 0.01193456527972926, -0.04973290349094079, -0.07726317316720414, 0.09405920349573646, 0.4207962846098268, -0.8259229974584023, 0.4207962846098268, 0.09405920349573646, -0.07726317316720414, -0.04973290349094079, 0.01193456527972926, 0.016990639867602342, -0.0019142861290887667, -0.0019088317364812906, 0.0 };
std::vector<double> reverse_biorthogonal6p8::lo_r = { 0.0019088317364812906, -0.0019142861290887667, -0.016990639867602342, 0.01193456527972926, 0.04973290349094079, -0.07726317316720414, -0.09405920349573646, 0.4207962846098268, 0.8259229974584023, 0.4207962846098268, -0.09405920349573646, -0.07726317316720414, 0.04973290349094079, 0.01193456527972926, -0.016990639867602342, -0.0019142861290887667, 0.0019088317364812906, 0.0 };
std::vector<double> reverse_biorthogonal6p8::hi_r = { 0.0, 0.0, 0.0, 0.0, 0.014426282505624435, -0.014467504896790148, -0.07872200106262882, 0.04036797903033992, 0.41784910915027457, -0.7589077294536541, 0.41784910915027457, 0.04036797903033992, -0.07872200106262882, -0.014467504896790148, 0.014426282505624435, 0.0, 0.0, 0.0 };