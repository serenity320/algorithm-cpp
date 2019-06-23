using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace AlgorithmAssist.Modules
{
    public class HotkeyManager
    {
        List<GlobalHotkey> _globalHotkey;

        public HotkeyManager()
        {
            _globalHotkey = new List<GlobalHotkey>();
        }

        public bool registerGlobalHotkey(int modifier, Keys keys, Form form)
        {
            bool result = false;

            GlobalHotkey globalHotkey = new GlobalHotkey(modifier, keys, form);

            result = globalHotkey.Register();
            if (result)
            {
                _globalHotkey.Add(globalHotkey);
            }

            return result;
        }

        public void unregiserGlobalHotkeys()
        {
            foreach (var element in _globalHotkey)
            {
                element.Unregiser();
            }

            _globalHotkey.Clear();
        }
    }
}
