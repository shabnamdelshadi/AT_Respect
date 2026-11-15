using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using USILogicLayer.Protocol;
using Extensions.ByteArrayExtensions;
using DataAccessLayer;
using System.Threading;
using System.IO;
using Extensions.Loggers;
using USILogicLayer.Algorithms.Algorithm_Forms;
using System.Diagnostics;
using USILogicLayer.Algorithms;


namespace USILogicLayer.Algorithms
{
    public class AT_Respect_Diag : Algorithm
    {
        public AT_Respect_Diag(RayanDataModelDataSet.ECURow ECU, LogicManager logicManager)
                                                                            : base(ECU, logicManager)
        {
            Messages["ATRespectDiag_AreYouSure", Language.English] = "Are you sure about performing the operation?";
            Messages["ATRespectDiag_AreYouSure", Language.Farsi] = "آیا از انجام عملیات اطمینان دارید؟";
                         
            Messages["ATRespectDiag_Canceled", Language.English] = "Operation canceled by user.";
            Messages["ATRespectDiag_Canceled", Language.Farsi] = "عملیات توسط کاربر لغو شد";
                         
            Messages["ATRespectDiag_Digit", Language.English] = " digit ";
            Messages["ATRespectDiag_Digit", Language.Farsi] = " رقم ";
                         
            Messages["ATRespectDiag_lessAllowedLimit", Language.English] = "The entered values are less than the allowed limit.";
            Messages["ATRespectDiag_lessAllowedLimit", Language.Farsi] = "مقادیر وارد شده کمتر از حد مجاز است.";
                         
            Messages["ATRespectDiag_EnterDate", Language.English] = " EnterDate ";
            Messages["ATRespectDiag_EnterDate", Language.Farsi] = " تاریخ را وارد کنید ";
                         
            Messages["ATRespectDiag_done", Language.English] = " Operation done ";
            Messages["ATRespectDiag_done", Language.Farsi] = " مقادیر وارد شده به درستی ثبت شد ";

            Messages["ATRespectDiag_conditions", Language.English] = "Ignition switch ON, handbrake engaged. Gear: P. Engine OFF.";
            Messages["ATRespectDiag_conditions", Language.Farsi] = "سوییچ باز باشد، ترمز دستی بالا باشد. دنده‌ی P. موتور خاموش.";

            Messages["ATRespectDiag_conditions1", Language.English] = "Ignition switch ON, handbrake engaged. Gear: R. Engine OFF.";
            Messages["ATRespectDiag_conditions1", Language.Farsi] = "سوییچ باز باشد، ترمز دستی بالا باشد. دنده‌ی R. موتور خاموش.";

            Messages["ATRespectDiag_conditions2", Language.English] = "Ignition switch ON, handbrake engaged. Gear: N. Engine OFF.";
            Messages["ATRespectDiag_conditions2", Language.Farsi] = "سوییچ باز باشد، ترمز دستی بالا باشد. دنده‌ی N. موتور خاموش.";

            Messages["ATRespectDiag_conditions3", Language.English] = "Ignition switch ON, handbrake engaged. Gear: D. Engine OFF.";
            Messages["ATRespectDiag_conditions3", Language.Farsi] = "سوییچ باز باشد، ترمز دستی بالا باشد. دنده‌ی D. موتور خاموش.";

            Messages["ATRespectDiag_conditions4", Language.English] = "Ignition switch ON, handbrake engaged. Gear: L. Engine OFF.";
            Messages["ATRespectDiag_conditions4", Language.Farsi] = "سوییچ باز باشد، ترمز دستی بالا باشد. دنده‌ی L. موتور خاموش.";

            Messages["ATRespectDiag_closed_wait", Language.English] = "Key switch OFF and wait for 2 seconds. Then the process ends.";
            Messages["ATRespectDiag_closed_wait", Language.Farsi] = "سوییچ بسته و منتظر بمانید ۲ ثانیه. سپس پروسه به اتمام میرسد.";
           
            Messages["ATRespectDiag_GearSensor_P_defined_successfully", Language.English] = "Gear sensor p successfully defined.";
            Messages["ATRespectDiag_GearSensor_P_defined_successfully", Language.Farsi] = "سنسور دنده p با موفقیت تعریف شد.";

            Messages["ATRespectDiag_GearSensor_R_defined_successfully", Language.English] = "Gear sensor R successfully defined.";
            Messages["ATRespectDiag_GearSensor_R_defined_successfully", Language.Farsi] = "سنسور دنده R با موفقیت تعریف شد.";

            Messages["ATRespectDiag_GearSensor_N_defined_successfully", Language.English] = "Gear sensor N successfully defined.";
            Messages["ATRespectDiag_GearSensor_N_defined_successfully", Language.Farsi] = "سنسور دنده N با موفقیت تعریف شد.";

            Messages["ATRespectDiag_GearSensor_D_defined_successfully", Language.English] = "Gear sensor D successfully defined.";
            Messages["ATRespectDiag_GearSensor_D_defined_successfully", Language.Farsi] = "سنسور دنده D با موفقیت تعریف شد.";

            Messages["ATRespectDiag_GearSensor_L_defined_successfully", Language.English] = "Gear sensor L successfully defined.";
            Messages["ATRespectDiag_GearSensor_L_defined_successfully", Language.Farsi] = "سنسور دنده L با موفقیت تعریف شد.";

            
        }
    }
}