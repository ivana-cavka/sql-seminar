#pragma once
#include "Relation.h"

namespace SqlSeminar {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for AddNewSchema
	/// </summary>
	public ref class AddNewSchema : public System::Windows::Forms::Form
	{
	public:
		AddNewSchema(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddNewSchema()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ LabelNewSchema;
	protected:
	private: System::Windows::Forms::TextBox^ TextBoxInputShema;
	private: System::Windows::Forms::Label^ LabelNewDependencies;
	private: System::Windows::Forms::TextBox^ TextBoxInputDependencies;
	private: System::Windows::Forms::Button^ ButtonAddRelation;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddNewSchema::typeid));
			this->LabelNewSchema = (gcnew System::Windows::Forms::Label());
			this->TextBoxInputShema = (gcnew System::Windows::Forms::TextBox());
			this->LabelNewDependencies = (gcnew System::Windows::Forms::Label());
			this->TextBoxInputDependencies = (gcnew System::Windows::Forms::TextBox());
			this->ButtonAddRelation = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// LabelNewSchema
			// 
			this->LabelNewSchema->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->LabelNewSchema->AutoSize = true;
			this->LabelNewSchema->BackColor = System::Drawing::Color::LightSlateGray;
			this->LabelNewSchema->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LabelNewSchema->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->LabelNewSchema->Location = System::Drawing::Point(145, 29);
			this->LabelNewSchema->Name = L"LabelNewSchema";
			this->LabelNewSchema->Size = System::Drawing::Size(149, 20);
			this->LabelNewSchema->TabIndex = 0;
			this->LabelNewSchema->Text = L"Upišite shemu:";
			// 
			// TextBoxInputShema
			// 
			this->TextBoxInputShema->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->TextBoxInputShema->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->TextBoxInputShema->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->TextBoxInputShema->Location = System::Drawing::Point(21, 83);
			this->TextBoxInputShema->Name = L"TextBoxInputShema";
			this->TextBoxInputShema->Size = System::Drawing::Size(393, 27);
			this->TextBoxInputShema->TabIndex = 1;
			this->TextBoxInputShema->TextChanged += gcnew System::EventHandler(this, &AddNewSchema::TextBoxInputShema_TextChanged);
			// 
			// LabelNewDependencies
			// 
			this->LabelNewDependencies->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->LabelNewDependencies->AutoSize = true;
			this->LabelNewDependencies->BackColor = System::Drawing::Color::LightSlateGray;
			this->LabelNewDependencies->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->LabelNewDependencies->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->LabelNewDependencies->Location = System::Drawing::Point(41, 140);
			this->LabelNewDependencies->Name = L"LabelNewDependencies";
			this->LabelNewDependencies->Size = System::Drawing::Size(359, 20);
			this->LabelNewDependencies->TabIndex = 2;
			this->LabelNewDependencies->Text = L"Upišite njene funkcijske ovisnosti:";
			// 
			// TextBoxInputDependencies
			// 
			this->TextBoxInputDependencies->Font = (gcnew System::Drawing::Font(L"Courier New", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->TextBoxInputDependencies->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->TextBoxInputDependencies->Location = System::Drawing::Point(21, 202);
			this->TextBoxInputDependencies->Name = L"TextBoxInputDependencies";
			this->TextBoxInputDependencies->Size = System::Drawing::Size(392, 27);
			this->TextBoxInputDependencies->TabIndex = 3;
			this->TextBoxInputDependencies->TextChanged += gcnew System::EventHandler(this, &AddNewSchema::TextBoxInputDependencies_TextChanged);
			// 
			// ButtonAddRelation
			// 
			this->ButtonAddRelation->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ButtonAddRelation->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ButtonAddRelation->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ButtonAddRelation->Location = System::Drawing::Point(149, 280);
			this->ButtonAddRelation->Name = L"ButtonAddRelation";
			this->ButtonAddRelation->Size = System::Drawing::Size(134, 27);
			this->ButtonAddRelation->TabIndex = 4;
			this->ButtonAddRelation->Text = L"DODAJ";
			this->ButtonAddRelation->UseVisualStyleBackColor = false;
			this->ButtonAddRelation->Click += gcnew System::EventHandler(this, &AddNewSchema::ButtonAddRelation_Click);
			// 
			// AddNewSchema
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(445, 361);
			this->Controls->Add(this->ButtonAddRelation);
			this->Controls->Add(this->TextBoxInputDependencies);
			this->Controls->Add(this->LabelNewDependencies);
			this->Controls->Add(this->TextBoxInputShema);
			this->Controls->Add(this->LabelNewSchema);
			this->Name = L"AddNewSchema";
			this->Text = L"Nova shema";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void TextBoxInputShema_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void TextBoxInputDependencies_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	public: Relation^ relation = nullptr;

	private: System::Void ButtonAddRelation_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ schema = this->TextBoxInputShema->Text;
		String^ dependencies = this->TextBoxInputDependencies->Text;

		if (schema->Length == 0 || dependencies->Length == 0) {
			MessageBox::Show("Neodgovarajuæ unos");
			return;
		}

		try {
			String^ connString = "Data Source=(localdb)\\MSSQLLocalDB;Initial Catalog=sql.seminar;Integrated Security=True";
			SqlConnection sqlConn(connString);
			sqlConn.Open();

			String^ sqlQuery = "SELECT Dependencies FROM Relation WHERE Schema=@schema AND Dependencies=@dependencies";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@schema", schema);
			command.Parameters->AddWithValue("@dependencies", dependencies);

			SqlDataReader^ reader = command.ExecuteReader();
			if (reader->Read()) {
				MessageBox::Show("Shema veæ postoji");
				return;
			}
			else {
				String^ sqlQueryFindMaxId = "SELECT MAX(Id) FROM Relation";
				SqlCommand command2(sqlQueryFindMaxId, % sqlConn);
				SqlDataReader^ reader2 = command2.ExecuteReader();
				int id = reader2->GetInt32(0) + 1;

				String^ sqlQueryInput = "INSERT INTO Relation (Id, Schema, Dependencies) VALUES (@id, @schema, @dependencies)";
				SqlCommand command3(sqlQueryInput, % sqlConn);
				command3.Parameters->AddWithValue("@id", id);
				command3.Parameters->AddWithValue("@schema", schema);
				command3.Parameters->AddWithValue("@dependencies", dependencies);
				command3.ExecuteNonQuery();
				this->Close();
			}
		}
		catch (Exception^ e) {
			MessageBox::Show("Baza nedostupna");
			return;
		}
	}
};
}
