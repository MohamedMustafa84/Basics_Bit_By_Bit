namespace ContactsWindowsForms
{
    partial class FrmListContact
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.DgvAllContacts = new System.Windows.Forms.DataGridView();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.CmsEditContact = new System.Windows.Forms.ToolStripMenuItem();
            this.CmsDeleteContact = new System.Windows.Forms.ToolStripMenuItem();
            this.btnAddNewContact = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.DgvAllContacts)).BeginInit();
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // DgvAllContacts
            // 
            this.DgvAllContacts.AllowUserToAddRows = false;
            this.DgvAllContacts.AllowUserToDeleteRows = false;
            this.DgvAllContacts.AllowUserToOrderColumns = true;
            this.DgvAllContacts.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DgvAllContacts.ContextMenuStrip = this.contextMenuStrip1;
            this.DgvAllContacts.Location = new System.Drawing.Point(0, 98);
            this.DgvAllContacts.Name = "DgvAllContacts";
            this.DgvAllContacts.ReadOnly = true;
            this.DgvAllContacts.Size = new System.Drawing.Size(932, 527);
            this.DgvAllContacts.TabIndex = 0;
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.CmsEditContact,
            this.CmsDeleteContact});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.RenderMode = System.Windows.Forms.ToolStripRenderMode.System;
            this.contextMenuStrip1.ShowImageMargin = false;
            this.contextMenuStrip1.Size = new System.Drawing.Size(156, 70);
            // 
            // CmsEditContact
            // 
            this.CmsEditContact.Name = "CmsEditContact";
            this.CmsEditContact.Size = new System.Drawing.Size(155, 22);
            this.CmsEditContact.Text = "Edit Contact";
            this.CmsEditContact.Click += new System.EventHandler(this.CmsEditContact_Click);
            // 
            // CmsDeleteContact
            // 
            this.CmsDeleteContact.Name = "CmsDeleteContact";
            this.CmsDeleteContact.Size = new System.Drawing.Size(155, 22);
            this.CmsDeleteContact.Text = "Delete Contact";
            this.CmsDeleteContact.Click += new System.EventHandler(this.CmsDeleteContact_Click);
            // 
            // btnAddNewContact
            // 
            this.btnAddNewContact.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.btnAddNewContact.Location = new System.Drawing.Point(778, 33);
            this.btnAddNewContact.Name = "btnAddNewContact";
            this.btnAddNewContact.Size = new System.Drawing.Size(134, 30);
            this.btnAddNewContact.TabIndex = 2;
            this.btnAddNewContact.Tag = "-1";
            this.btnAddNewContact.Text = "Add New Contact";
            this.btnAddNewContact.UseVisualStyleBackColor = true;
            this.btnAddNewContact.Click += new System.EventHandler(this.btnAddNewContact_Click);
            // 
            // FrmListContact
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(933, 450);
            this.Controls.Add(this.btnAddNewContact);
            this.Controls.Add(this.DgvAllContacts);
            this.Name = "FrmListContact";
            this.Text = "FrmListContact";
            this.Load += new System.EventHandler(this.FrmListContact_Load);
            ((System.ComponentModel.ISupportInitialize)(this.DgvAllContacts)).EndInit();
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.DataGridView DgvAllContacts;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem CmsEditContact;
        private System.Windows.Forms.ToolStripMenuItem CmsDeleteContact;
        private System.Windows.Forms.Button btnAddNewContact;
    }
}

