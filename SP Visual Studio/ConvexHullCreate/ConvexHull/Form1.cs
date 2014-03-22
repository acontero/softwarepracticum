using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace ConvexHull
{
    public partial class Form1 : Form
    {
        static Queue<Point> list = new Queue<Point>();
        static Queue<Point> convexhull = new Queue<Point>();
        static bool cv_loaded, list_loaded, drawing, firstGo, finished;
        System.Drawing.Graphics e1;
        static Pen pen1 = new Pen(Color.Red, 3);
        static Pen pen2 = new Pen(Color.Green, 3);
        Point f, prev, next;

        protected override void OnPaint(PaintEventArgs e)
        {
            base.OnPaint(e);


        }

        public Form1()
        {
            //finished = false;
            //drawing = false;
            //firstGo = true;
            InitializeComponent();
            //cv_loaded = false;
            //list_loaded = false;
            e1 = this.CreateGraphics();
        } 
        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void getMouse(object sender, MouseEventArgs e)
        {
            
                //f = new Point(e.X, e.Y);
                //list.Enqueue(f);
                //prev = f;
                //Point next = new Point(e.X, e.Y);
                //list.Enqueue(next);
                //e1.DrawLine(pen1, prev, next);
                //prev = next;
    
        } 

        private void Form1_MouseCaptureChanged(object sender, EventArgs e)
        {

        }

        private void keypressed(Object o, KeyPressEventArgs e)
        {

            //O key draws polygon from file
            if (e.KeyChar == (char)Keys.O)
            {

                OpenFileDialog openFileDialog1 = new OpenFileDialog();
                openFileDialog1.Filter = "All Files (*.*)|*.*|Plain Text Files (*.txt)|*.txt";
                openFileDialog1.FilterIndex = 2;
                openFileDialog1.RestoreDirectory = true;

                if (openFileDialog1.ShowDialog() == DialogResult.OK)
                {
                    try
                    {
                        e1.Clear(Color.White);
                        string name = openFileDialog1.FileName;
                        System.IO.StreamReader file = new System.IO.StreamReader(name);
                        list.Clear();
                        int count = 0;
                        String line = file.ReadLine();
                        String[] coords = line.Split(' ');
                        int x = Convert.ToInt32(coords[0]);
                        int y = Convert.ToInt32(coords[1]);
                        Point first = new Point(x, y);
                        Point next = new Point();
                        count++;
                        list.Enqueue(first);
                        Point previous = first;
                        while ((line = file.ReadLine()) != null)
                        {
                            coords = line.Split(' ');
                            x = Convert.ToInt32(coords[0]);
                            y = Convert.ToInt32(coords[1]);
                            next = new Point(x, y);
                            list.Enqueue(next);
                            count++;
                            e1.DrawLine(pen1, previous, next);
                            previous = next;
                        }
                        e1.DrawLine(pen1, previous, first);
                    }
                    catch (Exception IO)
                    {
                        Console.WriteLine("The file could not be read:");
                        Console.WriteLine(IO.Message);
                    }
                }
            }

            //Draws Convex Hull
            else if (e.KeyChar == (char)Keys.C)
            {
                Point[] points;
                convexhull.Clear();
                points = list.ToArray();
                points = sortPoints(points);
                int first, second, third;
                Point firstp = new Point();
                Point secondp = new Point();
                Point thirdp = new Point();
                int total = points.Length;
                float delta;
                for (int i = 0; i < total; i++)
                {
                    first = i % total;
                    second = (i + 1) % total;
                    third = (i + 2) % total;
                    firstp = points[first];
                    secondp = points[second];
                    thirdp = points[third];
                    delta = (secondp.X - firstp.X) * (thirdp.Y - firstp.Y) - (secondp.Y - firstp.Y) * (thirdp.X - firstp.X);
                    if (delta >= 0)
                    {
                        convexhull.Enqueue(secondp);
                    }
                }

               
                int count = 0;
                Point f = convexhull.ElementAt(0);
                count++;
                Point prev = f;
                while (count < convexhull.Count)
                {
                    Point n = convexhull.ElementAt(count);
                    count++;
                    e1.DrawLine(pen2, prev, n);
                    prev = n;
                }
                e1.DrawLine(pen2, prev, f);
                printPoints(convexhull);
            }

            else if (e.KeyChar == (char)Keys.D1)
            {
                e1.Clear(Color.White);
                Point[] p = list.ToArray();
                for (int i = 0; i < p.Length; i++) e1.DrawLine(pen1, p[i], p[(i + 1) % p.Length]);
            } 
            else if (e.KeyChar == (char)Keys.D2)
            {
                Point[] p = convexhull.ToArray();
                for (int i = 0; i < p.Length; i++) e1.DrawLine(pen2, p[i], p[(i + 1) % p.Length]);
            } 
            //else if (e.KeyChar == (char)Keys.S)
            //{
                //printPoints(convexhull);
            //}
    
        } 

        private Point[] sortPoints(Point[] p)
        {

            Point origin = p[0];
            Point[] answer = new Point[p.Length];
            double[] angles = new double[p.Length]; //angles[index in origininal polgon list] = angle to the origin from this polygon point
            for (int i = 1; i < p.Length; i++)
            {
                angles[i] = Math.Atan2(p[i].Y - origin.Y, p[i].X - origin.X);
            }

            answer[0] = origin;
            float zero = 0;
            for (int c = 1; c < p.Length; c++)
            {
                double min = 360;
                int minPosition = 0;
                for (int x = 1; x < p.Length; x++)
                {
                    if (angles[x] < min)
                    {
                        min = angles[x];
                        minPosition = x;
                    }
                }
                answer[c] = p[minPosition];
                angles[minPosition] = 1 / zero;
            }
            return answer;

        } 

        private void printPoints(Queue<Point> ch)
        {
            SaveFileDialog saveFileDialog1 = new SaveFileDialog();
            saveFileDialog1.Filter = "All Files (*.*)|*.*|Plain Text Files (*.txt)|*.txt";
            saveFileDialog1.FilterIndex = 2;
            saveFileDialog1.RestoreDirectory = true;

            if (saveFileDialog1.ShowDialog() == DialogResult.OK)
            {
                string name = saveFileDialog1.FileName;
                using (System.IO.StreamWriter file = new System.IO.StreamWriter(name))
                {
                    int count = ch.Count();
                    for (int i = 0; i < count; i++)
                    {
                        Point point = ch.Dequeue();
                        file.WriteLine(point.X + " " + point.Y);
                        ch.Enqueue(point);
                    }
                    file.Close();
                }
            }
        } 
    }
} 