namespace 密碼強度分析
{
    public partial class Form1 : Form
    {
        int num = 0, str = 0;
        public Form1()
        {
            InitializeComponent();
            label1.Text = "input string";
            button1.Text = "strlen";
            button2.Text = "run";
            button3.Text = "clear";
            button4.Text = "close";
            label2.Text = "";
            label4.Text = "";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string ch = textBox1.Text;
            int n = ch.Length;
            for (int i = 0; i < n; i++)
            {
                if ((int)ch[i] >= 48 && (int)ch[i] <= 57) num++;
                if ((int)ch[i] >= 97 && (int)ch[i] <= 122) str++;
            }
            label2.Text = str.ToString() + "," + num.ToString();

        }

        private void button2_Click(object sender, EventArgs e)
        {
            string ch = textBox1.Text;
            int n = ch.Length;
            if (n > 12)
            {
                if (num != 0 && str != 0)
                {
                    if (str > num)
                    {
                        label4.Text = "strong";
                    }
                }
            }
            else label4.Text = "weak";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label2.Text = "";
            label4.Text = "";
            num = 0;
            str = 0;
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
