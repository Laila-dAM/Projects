namespace DatabaseApp {
partial class Form1 {

private System.ComponentModel.IContainer components = null;
private System.Windows.Forms.TextBox txtName;
private System.Windows.Forms.NumericUpDown numAge;
private System.Windows.Forms.Button btnAdd;
private System.Windows.Forms.Button btnLoad;
private System.Windows.Forms.DataGridView dataGridView;

protected override void Dispose(bool disposing) {
    if(disposing && (components != null)) {
        components.Dispose();
}
base.Dispose(disposing);
}
private void InitializeComponent() {
    this.txtName = new System.Windows.Forms.TextBox();
    this.numAge = new System.Windows.Forms.NumericUpDown();
    this.btnAdd = new System.Windows.Forms.Button();
    this.btnLoad = new System.Windows.Forms.Button();
    this.dataGridView = new System.Windows.Forms.DataGridView();
 ((System.ComponentModel.ISupportInitialize)(this.numAge)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
            this.SuspendLayout();

this.txtName.Location = new System.Drawing.Point(12, 12);
this.txtName.Name = "txtName";
this.txtName.Size = new System.Drawing.Size(200, 20);
this.txtName.TabIndex = 0;
this.numAge.Location = new System.Drawing.Point(12, 38);
this.numAge.Name = "numAge";
this.numAge.Size = new System.Drawing.Size(200, 20);
this.numAge.TabIndex = 1;

this.btnAdd.Location = new System.Drawing.Point(12, 64);
this.btnAdd.Name = "btnAdd";
this.btnAdd.Size = new System.Drawing.Size(95, 23);
this.btnAdd.TabIndex = 2;
this.btnAdd.Text = "Add Data";
this.btnAdd.UseVisualStyleBackColor = true;
this.btnAdd.Click += new System.EventHandler(this.btnAdd_Click);
this.btnLoad.Location = new System.Drawing.Point(117, 64);
this.btnLoad.Name = "btnLoad";
this.btnLoad.Size = new System.Drawing.Size(95, 23);
this.btnLoad.TabIndex = 3;
this.btnLoad.Text = "Load Data";
this.btnLoad.UseVisualStyleBackColor = true;
this.btnLoad.Click += new System.EventHandler(this.btnLoad_Click);

this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
this.dataGridView.Location = new System.Drawing.Point(12, 93);
this.dataGridView.Name = "dataGridView";
this.dataGridView.Size = new System.Drawing.Size(400, 150);
this.dataGridView.TabIndex = 4;

this.ClientSize = new System.Drawing.Size(424, 261);
this.Controls.Add(this.dataGridView);
this.Controls.Add(this.btnLoad);
this.COntrols.Add(this.btnAdd);
this.Controls.Add(this.numAge);
this.Controls.Add(this.txtName);
this.Name = "Form1";
this.Text = "Database App";
this.Load += new System.EventHandler(this.Form1_Load);((System.ComponentModel.ISupportInitialize)(this.numAge)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

}
}
}