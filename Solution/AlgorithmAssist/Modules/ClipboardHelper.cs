using System.Windows.Forms;

namespace AlgorithmAssist.Modules
{
    public class ClipboardHelper
    {
        public ClipboardHelper()
        {

        }

        public void SetTextClipboard(string text, bool isPaste)
        {
            Clipboard.SetText(text + "\r\n");

            if (isPaste)
            {
                SendKeys.Send("^v");
            }
        }
    }
}
